/* Message Broker Implementation */

// Includes
#include "broker.h"

// Types
static broker_context_t m_context;

broker_context_t* broker_init(broker_topic_t* max_topics, uint32_t max_topics_length)
{
    if(max_topics_length == 0 || max_topics == NULL)
    {
        // No static subscriber memory allocated
        return NULL;
    }

    for(uint32_t i = 0; i < max_topics_length; i++)
    {
        if(max_topics[i]->listeners == NULL || max_topics[i]->listeners_length == 0)
        {
            // Topic has no listener static allocation
            return NULL;
        }
        memset(max_topics[i]->listeners, 0, sizeof(broker_listener_fn_t) * max_topics[i]->listeners_length);
    }

    m_context.topics = max_topics;
    m_context.topics_length= max_topics_length;
    m_context.initialized = true;
    return &m_context;
}

// TODO: Allow multiple listeners per topic
bool broker_subscribe(broker_context_t* context, broker_topic_index_t topic_index, broker_listener_fn_t listener)
{
    if(context == NULL || listener == NULL)
    {
        // TODO: error -> NULL_PARAMETER
        return false;
    }

    if(!context->initialized || context->topics == NULL)
    {
        // TODO: error -> CONTEXT_NOT_INITIALIZED
        return false;
    }

    if(topic_index >= context->topics_length)
    {
        // TODO: error -> TOPIC_OUT_OF_RANGE
        return false;
    }

    // TODO: Improve this search...can we use hash tables?
    for(uint32_t i = 0; i < context->topics[topic_index]->listeners_length; i++)
    {
        if(context->topics[topic_index]->listeners[i] == listener)
        {
            // Already subscribed to this topic
            // TODO: return -> SUBSCRIBE_SUCCESS
            return true;
        }
    }

    for(uint32_t i = 0; i < context->topics[topic_index]->listeners_length; i++)
    {
        if(context->topics[topic_index]->listeners[i] == NULL)
        {
            // Subscribe
            context->topics[topics_index]->listeners[i] = listener;
            // TODO: return -> SUBSCRIBE_SUCCESS
            return true;
        }
    }

    // Max number of topics reached
    // TODO: error -> MAX_NUMBER_SUBSCRIBERS_PER_TOPIC_REACHED
    return false;
}

bool broker_publish(broker_context_t* context, broker_topic_index_t topic_index, void* event)
{

    if(context == NULL || event == NULL)
    {
        // TODO: error -> NULL_PARAMETER
        return false;
    }

    if(!context->initialized || context->topics == NULL)
    {
        // TODO: error -> CONTEXT_NOT_INITIALIZED
        return false;
    }

    if(topic_index >= context->topics_length)
    {
        // TODO: error -> TOPIC_OUT_OF_RANGE
        return false;
    }

    // Fire all event listeners for the topic sequentially
    for(uint32_t i = 0; i < context->topics[topic_index]->listeners_length; i++)
    {
        if(context->topics[topic_index]->listeners[i] != NULL)
        {
            context->topics[topic_index]->listener[i](event);
            // TODO: return -> PUBLISH_SUCCESS
            return true;
        }
    }

    // TODO: error -> PUBLISH_FAILED
    return false;
}
