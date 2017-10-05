/* Message Broker Implementation */

// Includes
#include "broker.h"

// Types
static broker_context_t m_context;

broker_context_t* broker_init(broker_subscriber_t* subscribers_array, uint32_t subscribers_array_length)
{
    if(subscribers_array_length == 0 || subscribers_array == NULL)
    {
        // No static subscriber memory allocated
        return NULL;
    }

    memset(subscribers_array, 0, sizeof(broker_subscriber_t) * subscribers_array_length);
    m_context.subscribers = subscribers_array;
    m_context.subscribers_length = subscribers_array_length;
    m_context.initialized = true;
    return &m_context;
}

// TODO: Allow multiple topics per listener, or multiple listeners per topic?
bool broker_subscribe(broker_context_t* context, broker_topic_t topic, broker_listener_fn_t listener)
{
    if(context == NULL || listener == NULL)
    {
        return false;
    }

    if(!context->initialized)
    {
        return false;
    }

    for(uint32_t i = 0; i < context->subscribers_length; i++)
    {
        if(context->subscribers[i].listener == NULL)
        {
            // Subscribe
            context->subscribers[i].topic = topic;
            context->subscribers[i].listener = listener;
            return true;
        }
        else if(context->subscribers[i].listener == listener && context->subscribers[i].topic == topic)
        {
            // Already subscribed
            return true;
        }
    }

    // Max number of subscribers reached
    return false;
}

bool broker_publish(broker_context_t* context, broker_topic_t topic, void* event)
{
    return false;
}
