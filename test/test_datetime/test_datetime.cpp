#include <unity.h>

#include "../../src/utils/date_time.h"

void setUp(void) {}

void tearDown(void) {}

void test_default_constructor_starts_at_midnight()
{
    const Utils::DateTime time;

    TEST_ASSERT_EQUAL_UINT32(0, time.ToSecondsOfDay());
    TEST_ASSERT_EQUAL_STRING("00:00", time.ToString().c_str());
}

void test_component_constructor_sets_time()
{
    const Utils::DateTime time(23, 59, 58);

    TEST_ASSERT_EQUAL_UINT32(86398, time.ToSecondsOfDay());
    TEST_ASSERT_EQUAL_UINT32(1439, time.ToMinutesOfDay());
    TEST_ASSERT_EQUAL_STRING("23:59", time.ToString().c_str());
}

void test_component_constructor_wraps_values_to_valid_ranges()
{
    const Utils::DateTime time(25, 61, 60);

    TEST_ASSERT_EQUAL_UINT32(3660, time.ToSecondsOfDay());
    TEST_ASSERT_EQUAL_STRING("01:01", time.ToString().c_str());
}

void test_seconds_constructor_wraps_after_one_day()
{
    const Utils::DateTime time(90061);

    TEST_ASSERT_EQUAL_UINT32(3661, time.ToSecondsOfDay());
    TEST_ASSERT_EQUAL_STRING("01:01", time.ToString().c_str());
}

void test_set_updates_and_normalizes_time()
{
    Utils::DateTime time;

    time.Set(24, 60, 60);

    TEST_ASSERT_EQUAL_UINT32(0, time.ToSecondsOfDay());
    TEST_ASSERT_EQUAL_STRING("00:00", time.ToString().c_str());
}

void test_equality_includes_seconds()
{
    const Utils::DateTime first(12, 30, 0);
    const Utils::DateTime sameTime(12, 30, 0);
    const Utils::DateTime differentSecond(12, 30, 1);

    TEST_ASSERT_TRUE(first == sameTime);
    TEST_ASSERT_FALSE(first == differentSecond);
}

void test_ordering_includes_seconds()
{
    const Utils::DateTime earlier(12, 30, 1);
    const Utils::DateTime later(12, 30, 2);

    TEST_ASSERT_TRUE(earlier < later);
    TEST_ASSERT_FALSE(later < earlier);
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    UNITY_BEGIN();
    RUN_TEST(test_default_constructor_starts_at_midnight);
    RUN_TEST(test_component_constructor_sets_time);
    RUN_TEST(test_component_constructor_wraps_values_to_valid_ranges);
    RUN_TEST(test_seconds_constructor_wraps_after_one_day);
    RUN_TEST(test_set_updates_and_normalizes_time);
    RUN_TEST(test_equality_includes_seconds);
    RUN_TEST(test_ordering_includes_seconds);
    return UNITY_END();
}
