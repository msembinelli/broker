/* Message Broker Header */

// Includes
#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

// Macros
// Number of modules subscribed to the event stream
#define MAX_NUMBER_SUBSCRIBERS 8

// Types
typedef uint32_t broker_topic_t;

typedef struct
{
    broker_topic_t    topic;
    void (*broker_listener_t)(void*);
} broker_subscriber_t;

typedef struct
{
    broker_subscriber_t* subscribers;
} broker_context_t;

// Prototypes
broker_context_t* broker_init(broker_subscriber_t* subscriber_allocation);
// boolean broker_subscribe(broker_topic topic, broker_listener listener);
// boolean broker_publish(broker_topic topic, (void*)event);
