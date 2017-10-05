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
    broker_subscriber_t subscribers_array[MAX_NUMBER_OF_SUBSCRIBERS];
    context.subscribers = subscribers_array;
    TEST_ASSERT_EQUAL_MEMORY(&context, broker_init(subscribers_array, ARRAY_LENGTH(subscribers_array)), sizeof(broker_context_t));
}

void test_broker_subscribe_should_NotInitializeContext(void)
{
    broker_subscriber_t* subscribers_array_ptr;
    TEST_ASSERT_NULL(broker_init(subscribers_array_ptr, ARRAY_LENGTH(subscribers_array_ptr)));

    TEST_ASSERT_NULL(broker_init(NULL, 2));

    TEST_ASSERT_NULL(broker_init(NULL, 0));

    broker_subscriber_t subscribers_array[MAX_NUMBER_OF_SUBSCRIBERS];
    TEST_ASSERT_NULL(broker_init(subscribers_array, 0));
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
    RUN_TEST(test_broker_subscribe_should_NotInitializeContext);
    // RUN_TEST(test_broker_subscribe_should_AllowSubscription);
    // RUN_TEST(test_broker_subscribe_should_NotAllowSubscription);
    return UNITY_END();
}
