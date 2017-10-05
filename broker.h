/* Message Broker Header */

// Includes
#include "stdint.h"
#include "stdbool.h"
#include "stddef.h"
#include "stdlib.h"
#include "string.h"

// Macros
#define ARRAY_LENGTH(x) sizeof(x)/sizeof(x[0])

// Types
typedef uint32_t broker_topic_t;
typedef void (*broker_listener_t)(void*);

typedef struct
{
    broker_topic_t    topic;
    broker_listener_t broker_listener;
} broker_subscriber_t;

typedef struct
{
    broker_subscriber_t* subscribers;
} broker_context_t;

// Prototypes
broker_context_t* broker_init(broker_subscriber_t* subscribers_array, uint32_t subscribers_array_length);
bool broker_subscribe(broker_topic_t topic, broker_listener_t broker_listener);
bool broker_publish(broker_topic_t topic, void* event);
