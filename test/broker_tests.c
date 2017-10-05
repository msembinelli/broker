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
    broker_context_t expected_context;
    broker_subscriber_t expected_subscribers_array[MAX_NUMBER_OF_SUBSCRIBERS];
    memset(expected_subscribers_array, 0, sizeof(broker_subscriber_t) * MAX_NUMBER_OF_SUBSCRIBERS);
    expected_context.subscribers = expected_subscribers_array;
    expected_context.subscribers_length = MAX_NUMBER_OF_SUBSCRIBERS;
    expected_context.initialized = true;
    broker_subscriber_t subscribers_array[MAX_NUMBER_OF_SUBSCRIBERS];

    TEST_ASSERT_NOT_NULL(broker_init(subscribers_array, MAX_NUMBER_OF_SUBSCRIBERS));

    TEST_ASSERT_EQUAL_MEMORY(expected_context.subscribers, broker_init(subscribers_array, MAX_NUMBER_OF_SUBSCRIBERS)->subscribers, sizeof(broker_subscriber_t) * MAX_NUMBER_OF_SUBSCRIBERS);

    broker_subscriber_t subscribers_array_shared[MAX_NUMBER_OF_SUBSCRIBERS];
    expected_context.subscribers = subscribers_array_shared;
    expected_context.subscribers_length = MAX_NUMBER_OF_SUBSCRIBERS;

    TEST_ASSERT_EQUAL_MEMORY(subscribers_array_shared, broker_init(subscribers_array_shared, MAX_NUMBER_OF_SUBSCRIBERS)->subscribers, sizeof(broker_subscriber_t) * MAX_NUMBER_OF_SUBSCRIBERS);

    TEST_ASSERT_EQUAL_MEMORY(&expected_context, broker_init(subscribers_array_shared, MAX_NUMBER_OF_SUBSCRIBERS), sizeof(broker_context_t));

    TEST_ASSERT_TRUE(broker_init(subscribers_array_shared, MAX_NUMBER_OF_SUBSCRIBERS)->initialized);
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

typedef enum
{
    EVENT_1,
    EVENT_2,
} helper_event;

void test_helper_listener(void* event)
{
    switch((helper_event)event)
    {
        case EVENT_1:
            printf("Listener EVENT_1 Executed");
            break;
        case EVENT_2:
            printf("Listener EVENT_2 Executed");
            break;
    }
}

void test_broker_subscribe_should_AllowSubscription(void)
{
    broker_subscriber_t subscribers[MAX_NUMBER_OF_SUBSCRIBERS];
    broker_context_t* context = broker_init(subscribers, MAX_NUMBER_OF_SUBSCRIBERS);
    broker_topic_t topic = 0;
    broker_listener_fn_t listener = test_helper_listener;

    // Subscribe
    TEST_ASSERT_TRUE(broker_subscribe(context, topic, listener));

    // Subscribe again, same topic/listener
    TEST_ASSERT_TRUE(broker_subscribe(context, topic, listener));

    broker_topic_t new_topic = 1111;
    TEST_ASSERT_TRUE(broker_subscribe(context, new_topic, listener));
}

void test_broker_subscribe_should_NotAllowSubscription(void)
{
    broker_subscriber_t subscribers[MAX_NUMBER_OF_SUBSCRIBERS];
    broker_context_t* context = broker_init(subscribers, MAX_NUMBER_OF_SUBSCRIBERS);
    broker_topic_t topic = 0;
    broker_listener_fn_t listener = test_helper_listener;

    TEST_ASSERT_FALSE(broker_subscribe(NULL, topic, NULL));

    TEST_ASSERT_FALSE(broker_subscribe(context, topic, NULL));

    TEST_ASSERT_FALSE(broker_subscribe(NULL, topic, listener));

    // Hit max subscribers
    for(uint32_t i = 0; i < MAX_NUMBER_OF_SUBSCRIBERS; i++)
    {
        broker_subscribe(context, i, listener);
    }
    TEST_ASSERT_FALSE(broker_subscribe(context, 8, listener));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_broker_subscribe_should_InitializeContext);
    RUN_TEST(test_broker_subscribe_should_NotInitializeContext);
    RUN_TEST(test_broker_subscribe_should_AllowSubscription);
    RUN_TEST(test_broker_subscribe_should_NotAllowSubscription);
    return UNITY_END();
}
