/* Message Broker Header */

// Includes
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

// Macros

// Types
typedef uint32_t broker_topic_index_t;
void (*broker_listener_fn_t)((void*));

typedef struct
{
    broker_listener_fn_t* listeners;
    uint32_t*             listeners_length;
} broker_topic_t;

typedef struct
{
    broker_topic_t*       topics;
    uint32_t              topics_length;
    boolean               initialized;
} broker_context_t;

// Prototypes
broker_context_t* broker_init(broker_topic_t* max_topics, uint32_t max_topics_length);
boolean broker_subscribe(broker_context_t* context, broker_topic_index_t topic_index, broker_listener_fn_t listener);
boolean broker_publish(broker_context_t* context, broker_topic_index_t topic_index, (void*)event);
