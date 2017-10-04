/* Message Broker Tests */

// Includes
#include "unity.h"
#include "broker.h"

// Macros
#define MAX_NUMBER_OF_SUBSCRIBERS 8

// Types

// Procedures
void test_broker_subscribe_should_InitializeContext(void)
{
    broker_context_t context;
    broker_subscriber_t subscribers[MAX_NUMBER_OF_SUBSCRIBERS];
    context.subscribers = subscribers;
    TEST_ASSERT_EQUAL_MEMORY(&context, broker_init(&subscribers), sizeof(broker_context_t));
}

/* void test_helper_listener(uint8_t* array)
{
    printf("Listener Executed");
}

void test_broker_subscribe_should_AllowSubscription(void)
{
    broker_topic topic = 0;
    broker_listener listener =  test_helper_listener;
    TEST_ASSERT(true, broker_subscribe(topic, listener));
}

void test_broker_subscribe_should_NotAllowSubscription(void)
{
    broker_topic topic = 0;
    TEST_ASSERT(false, broker_subscribe(topic, NULL));
} */

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_broker_subscribe_should_InitializeContext);
    // RUN_TEST(test_broker_subscribe_should_AllowSubscription);
    // RUN_TEST(test_broker_subscribe_should_NotAllowSubscription);
    return UNITY_END();
}
