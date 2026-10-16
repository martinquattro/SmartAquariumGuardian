#include <unity.h>

#include "../../src/managers/comms/json_parser.h"

void setUp(void) {}

void tearDown(void) {}

void test_valid_json_is_accepted()
{
    const Utils::JsonPayloadParser parser(R"({"method":"feed"})");

    TEST_ASSERT_TRUE(parser.IsValid());
    TEST_ASSERT_TRUE(parser.GetError().empty());
}

void test_invalid_json_returns_error()
{
    const Utils::JsonPayloadParser parser(R"({"method":)");

    TEST_ASSERT_FALSE(parser.IsValid());
    TEST_ASSERT_EQUAL_STRING("Invalid JSON format.", parser.GetError().c_str());
}

void test_get_method_returns_method_string()
{
    const Utils::JsonPayloadParser parser(R"({"method":"feed"})");
    const auto method = parser.GetMethod();

    TEST_ASSERT_TRUE(method.has_value());
    TEST_ASSERT_EQUAL_STRING("feed", method->c_str());
}

void test_get_method_returns_empty_for_missing_or_wrong_type()
{
    const Utils::JsonPayloadParser missingMethod(R"({"params":{}})");
    const Utils::JsonPayloadParser wrongType(R"({"method":42})");

    TEST_ASSERT_FALSE(missingMethod.GetMethod().has_value());
    TEST_ASSERT_FALSE(wrongType.GetMethod().has_value());
}

void test_get_value_extracts_supported_types()
{
    const Utils::JsonPayloadParser parser(
        R"({"count":3,"temperature":24.5,"enabled":true,"name":"tank"})");

    const auto count = parser.GetValue<int>("count");
    const auto temperature = parser.GetValue<float>("temperature");
    const auto enabled = parser.GetValue<bool>("enabled");
    const auto name = parser.GetValue<std::string>("name");

    TEST_ASSERT_TRUE(count.has_value());
    TEST_ASSERT_EQUAL_INT(3, *count);
    TEST_ASSERT_TRUE(temperature.has_value());
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 24.5f, *temperature);
    TEST_ASSERT_TRUE(enabled.has_value());
    TEST_ASSERT_TRUE(*enabled);
    TEST_ASSERT_TRUE(name.has_value());
    TEST_ASSERT_EQUAL_STRING("tank", name->c_str());
}

void test_get_value_returns_empty_for_missing_key_or_type_mismatch()
{
    const Utils::JsonPayloadParser parser(R"({"count":"three"})");

    TEST_ASSERT_FALSE(parser.GetValue<int>("missing").has_value());
    TEST_ASSERT_FALSE(parser.GetValue<int>("count").has_value());
}

void test_get_value_maps_null_numbers_to_zero()
{
    const Utils::JsonPayloadParser parser(R"({"integer":null,"decimal":null})");
    const auto integer = parser.GetValue<int>("integer");
    const auto decimal = parser.GetValue<float>("decimal");

    TEST_ASSERT_TRUE(integer.has_value());
    TEST_ASSERT_EQUAL_INT(0, *integer);
    TEST_ASSERT_TRUE(decimal.has_value());
    TEST_ASSERT_EQUAL_FLOAT(0.0f, *decimal);
}

void test_get_param_reads_only_from_params_object()
{
    const Utils::JsonPayloadParser parser(
        R"({"count":99,"params":{"count":3,"enabled":true}})");

    const auto count = parser.GetParam<int>("count");
    const auto enabled = parser.GetParam<bool>("enabled");

    TEST_ASSERT_TRUE(count.has_value());
    TEST_ASSERT_EQUAL_INT(3, *count);
    TEST_ASSERT_TRUE(enabled.has_value());
    TEST_ASSERT_TRUE(*enabled);
    TEST_ASSERT_FALSE(parser.GetParam<int>("missing").has_value());
}

void test_get_param_returns_empty_when_params_is_missing_or_not_an_object()
{
    const Utils::JsonPayloadParser missingParams(R"({"count":3})");
    const Utils::JsonPayloadParser invalidParams(R"({"params":[]})");

    TEST_ASSERT_FALSE(missingParams.GetParam<int>("count").has_value());
    TEST_ASSERT_FALSE(invalidParams.GetParam<int>("count").has_value());
}

void test_invalid_parser_does_not_return_values()
{
    const Utils::JsonPayloadParser parser("not json");

    TEST_ASSERT_FALSE(parser.GetValue<int>("count").has_value());
    TEST_ASSERT_FALSE(parser.GetParam<int>("count").has_value());
    TEST_ASSERT_FALSE(parser.GetMethod().has_value());
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    UNITY_BEGIN();
    RUN_TEST(test_valid_json_is_accepted);
    RUN_TEST(test_invalid_json_returns_error);
    RUN_TEST(test_get_method_returns_method_string);
    RUN_TEST(test_get_method_returns_empty_for_missing_or_wrong_type);
    RUN_TEST(test_get_value_extracts_supported_types);
    RUN_TEST(test_get_value_returns_empty_for_missing_key_or_type_mismatch);
    RUN_TEST(test_get_value_maps_null_numbers_to_zero);
    RUN_TEST(test_get_param_reads_only_from_params_object);
    RUN_TEST(test_get_param_returns_empty_when_params_is_missing_or_not_an_object);
    RUN_TEST(test_invalid_parser_does_not_return_values);
    return UNITY_END();
}
