/* Message Broker Implementation */

// Includes
#include "broker.h"

// Macros
#define BROKER_CONTEXT_EMPTY 0

static broker_context_t m_context;

broker_context_t* broker_init(broker_subscriber_t* max_subscribers)
{
    memset(max_subscribers, BROKER_CONTEXT_EMPTY, sizeof(broker_subscriber_t));
    m_context.subscribers = max_subscribers;
    return &m_context;
}
