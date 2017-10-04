/* Message Broker Header */

// Includes
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

// Macros
// Number of modules subscribed to the event stream
#define MAX_NUMBER_SUBSCRIBERS 8

// Types
typedef uint32_t broker_topic_t;
void (*broker_listener)((void*));

typedef struct
{
    broker_topic    topic;
    broker_listener listener;
} broker_subscriber_t;

typedef struct
{
    broker_subscriber_t* subscribers;
} broker_context_t;

// Prototypes
boolean broker_init(broker_context_t* context);
boolean broker_subscribe(broker_topic topic, broker_listener listener);
boolean broker_publish(broker_topic topic, (void*)event);
