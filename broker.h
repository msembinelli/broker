/**********************************************************
 * Name:
 *     broker.h
 *
 * Description:
 *     Header for embedded statically allocated message
 *     broker.
 *
 * Copyright (c) 2017 Matthew Sembinelli
 *********************************************************/
#ifndef BROKER_H
#define BROKER_H

/**********************************************************
 * Includes
 *********************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/**********************************************************
 * Types
 *********************************************************/
typedef enum
{
    BROKER_RETURN_BASE                   = (0x00),

    BROKER_SUCCESS                       = (BROKER_RETURN_BASE + 0),
    BROKER_ERROR_NULL_PARAMETER          = (BROKER_RETURN_BASE + 1),
    BROKER_ERROR_NOT_INITIALIZED         = (BROKER_RETURN_BASE + 2),

    BROKER_RETURN_MAX                    = (0xFF)
} broker_return_t;

typedef uint32_t broker_topic_index_t;
typedef void (*broker_subscriber_fn_t)(void*);

typedef struct
{
    broker_subscriber_fn_t* listeners;
    uint32_t*             listeners_length;
} broker_topic_t;

typedef struct
{
    broker_topic_t*       topics;
    uint32_t              topics_length;
    bool                  initialized;
} broker_context_t;

/**********************************************************
 * Macros
 *********************************************************/
#define BROKER(context_name, event_union_type, max_subscribers_length, max_event_queue_length) \

/**********************************************************
 * Prototypes
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
uint32_t broker_init(broker_context_t* const ctx);

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
uint32_t broker_subscribe(broker_context_t* ctx, broker_topic_index_t topic_index, broker_subscriber_fn_t subscriber);

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
uint32_t broker_publish(broker_context_t* ctx, broker_topic_index_t topic_index, void* event);

#endif /* BROKER_H */
