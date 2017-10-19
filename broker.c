/**********************************************************
 * Name:
 *     broker.c
 *
 * Description:
 *     Implementation for embedded statically allocated
 *     message broker.
 *
 * Copyright (c) 2017 Matthew Sembinelli
 *********************************************************/
/**********************************************************
 * Includes
 *********************************************************/
#include "broker.h"
#include <string.h>

/**********************************************************
 * Procedures
 *********************************************************/
/**********************************************************
 * Name:
 *    broker_init
 *
 * Description:
 *    Initializes the broker context.
 *
 * Parameters:
 *    broker_context_t* const ctx - Pointer to the broker
 *                                  context.
 *
 * Returns:
 *    BROKER_SUCCESS - Successfully initialized broker.
 *    BROKER_ERROR_NULL_PARAMETER - When ctx is NULL.
 *********************************************************/
uint32_t broker_init(broker_context_t* const ctx)
{
    broker_return_t ret = BROKER_SUCCESS;

    if(NULL == ctx)
    {
        ret = BROKER_ERROR_NULL_PARAMETER;
    }
    else if(false == ctx->initialized)
    {
        ret = BROKER_ERROR_NOT_INITIALIZED;
    }

    // if(max_topics_length == 0 || max_topics == NULL)
    // {
    //     // No static subscriber memory allocated
    //     return NULL;
    // }
    //
    // for(uint32_t i = 0; i < max_topics_length; i++)
    // {
    //     if(max_topics[i]->listeners == NULL || max_topics[i]->listeners_length == 0)
    //     {
    //         // Topic has no listener static allocation
    //         return NULL;
    //     }
    //     memset(max_topics[i]->listeners, 0, sizeof(broker_listener_fn_t) * max_topics[i]->listeners_length);
    // }
    //
    // m_context.topics = max_topics;
    // m_context.topics_length= max_topics_length;
    // m_context.initialized = true;

    return ret;
}

/**********************************************************
 * Name:
 *    broker_subscribe
 *
 * Description:
 *    Registers subscriber callback with the broker context
 *    for the given topic index.
 *
 * Parameters:
 *    broker_context_t* const ctx - Pointer to the broker
 *                                  context.
 *
 * Returns:
 *    BROKER_SUCCESS - Successfully subscribed.
 *    BROKER_ERROR_NULL_PARAMETER - When any input pointers
 *                                  are NULL.
 *    BROKER_ERROR_NOT_INITIALIZED - ctx not intialized.
 *********************************************************/
uint32_t broker_subscribe(broker_context_t* ctx, broker_topic_index_t topic_index, broker_subscriber_fn_t subscriber)
{
    broker_return_t ret = BROKER_SUCCESS;

    if(NULL == ctx || NULL == subscriber)
    {
        ret = BROKER_ERROR_NULL_PARAMETER;
    }
    else if(false == ctx->initialized)
    {
        ret = BROKER_ERROR_NOT_INITIALIZED;
    }
    // if(context == NULL || listener == NULL)
    // {
    //     // TODO: error -> NULL_PARAMETER
    //     return false;
    // }
    //
    // if(!context->initialized || context->topics == NULL)
    // {
    //     // TODO: error -> CONTEXT_NOT_INITIALIZED
    //     return false;
    // }
    //
    // if(topic_index >= context->topics_length)
    // {
    //     // TODO: error -> TOPIC_OUT_OF_RANGE
    //     return false;
    // }
    //
    // // TODO: Improve this search...can we use hash tables?
    // for(uint32_t i = 0; i < context->topics[topic_index]->listeners_length; i++)
    // {
    //     if(context->topics[topic_index]->listeners[i] == listener)
    //     {
    //         // Already subscribed to this topic
    //         // TODO: return -> SUBSCRIBE_SUCCESS
    //         return true;
    //     }
    // }
    //
    // for(uint32_t i = 0; i < context->topics[topic_index]->listeners_length; i++)
    // {
    //     if(context->topics[topic_index]->listeners[i] == NULL)
    //     {
    //         // Subscribe
    //         context->topics[topics_index]->listeners[i] = listener;
    //         // TODO: return -> SUBSCRIBE_SUCCESS
    //         return true;
    //     }
    // }
    //
    // // Max number of topics reached
    // // TODO: error -> MAX_NUMBER_SUBSCRIBERS_PER_TOPIC_REACHED
    // return false;
    return ret;
}

/**********************************************************
 * Name:
 *    broker_publish
 *
 * Description:
 *    Publishes a message to the broker queue for the given
 *    topic.
 *
 * Parameters:
 *    broker_context_t* const ctx - Pointer to the broker
 *                                  context.
 *
 * Returns:
 *    BROKER_SUCCESS - Successfully published.
 *    BROKER_ERROR_NULL_PARAMETER - When any input pointers
 *                                  are NULL.
 *    BROKER_ERROR_NOT_INITIALIZED - ctx not intialized.
 *********************************************************/
uint32_t broker_publish(broker_context_t* ctx, broker_topic_index_t topic_index, void* event)
{
    broker_return_t ret = BROKER_SUCCESS;

    if(NULL == ctx)
    {
        ret = BROKER_ERROR_NULL_PARAMETER;
    }
    else if(false == ctx->initialized)
    {
        ret = BROKER_ERROR_NOT_INITIALIZED;
    }
    // if(context == NULL || event == NULL)
    // {
    //     // TODO: error -> NULL_PARAMETER
    //     return false;
    // }
    //
    // if(!context->initialized || context->topics == NULL)
    // {
    //     // TODO: error -> CONTEXT_NOT_INITIALIZED
    //     return false;
    // }
    //
    // if(topic_index >= context->topics_length)
    // {
    //     // TODO: error -> TOPIC_OUT_OF_RANGE
    //     return false;
    // }
    //
    // // Fire all event listeners for the topic sequentially
    // for(uint32_t i = 0; i < context->topics[topic_index]->listeners_length; i++)
    // {
    //     if(context->topics[topic_index]->listeners[i] != NULL)
    //     {
    //         context->topics[topic_index]->listener[i](event);
    //         // TODO: return -> PUBLISH_SUCCESS
    //         return true;
    //     }
    // }
    //
    // // TODO: error -> PUBLISH_FAILED
    // return false;
    return ret;
}
