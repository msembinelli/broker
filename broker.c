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
    return &m_context;
}
