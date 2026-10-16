#include <unity.h>

#include "../../src/drivers/tds_sensor.h"
#include <limits>
#include <utility>
#include <vector>

class MockTdsSensor : public Drivers::TdsSensor
{
    public:

        MockTdsSensor()
            : TdsSensor()
        {
        }

        void SetReadings(std::vector<float> readings)
        {
            _readings = std::move(readings);
            _nextReading = 0;
        }

    protected:

        float GetAnalogReading() override
        {
            return _readings.at(_nextReading++);
        }

    private:

        std::vector<float> _readings;
        std::size_t _nextReading = 0;
};

void setUp(void) {}

void tearDown(void) {}

void test_sensor_converts_a_mocked_voltage_to_ppm()
{
    MockTdsSensor sensor;
    sensor.SetReadings({1.0f});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();

    TEST_ASSERT_EQUAL_INT(273, sensor.GetLastReading());
}

void test_sensor_averages_mocked_voltage_samples()
{
    MockTdsSensor sensor;
    sensor.SetReadings({0.8f, 1.4f});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();
    sensor.Update();

    TEST_ASSERT_EQUAL_INT(302, sensor.GetLastReading());
}

void test_invalid_voltage_is_ignored_and_does_not_change_average()
{
    MockTdsSensor sensor;
    sensor.SetReadings({1.0f, -0.1f, 3.31f, std::numeric_limits<float>::quiet_NaN(), 1.4f});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();
    TEST_ASSERT_EQUAL_INT(273, sensor.GetLastReading());

    sensor.Update();
    sensor.Update();
    sensor.Update();
    TEST_ASSERT_EQUAL_INT(273, sensor.GetLastReading());

    sensor.Update();
    TEST_ASSERT_EQUAL_INT(331, sensor.GetLastReading());
}

void test_temperature_compensation_adjusts_tds_result()
{
    MockTdsSensor sensor;
    sensor.SetReadings({1.2f});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.SetTemperature(35.0f);
    sensor.Update();

    TEST_ASSERT_EQUAL_INT(273, sensor.GetLastReading());
}

void test_average_discards_voltage_samples_older_than_twelve_readings()
{
    MockTdsSensor sensor;
    sensor.SetReadings({
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f
    });

    TEST_ASSERT_TRUE(sensor.Init());
    for (int i = 0; i < 12; ++i)
    {
        sensor.Update();
    }
    TEST_ASSERT_EQUAL_INT(273, sensor.GetLastReading());

    sensor.Update();
    TEST_ASSERT_EQUAL_INT(297, sensor.GetLastReading());
}

void test_sensor_accepts_voltage_at_adc_range_boundaries()
{
    MockTdsSensor sensor;
    sensor.SetReadings({0.0f, 3.3f});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();
    TEST_ASSERT_EQUAL_INT(0, sensor.GetLastReading());

    sensor.Update();
    TEST_ASSERT_EQUAL_INT(490, sensor.GetLastReading());
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    UNITY_BEGIN();
    RUN_TEST(test_sensor_converts_a_mocked_voltage_to_ppm);
    RUN_TEST(test_sensor_averages_mocked_voltage_samples);
    RUN_TEST(test_invalid_voltage_is_ignored_and_does_not_change_average);
    RUN_TEST(test_temperature_compensation_adjusts_tds_result);
    RUN_TEST(test_average_discards_voltage_samples_older_than_twelve_readings);
    RUN_TEST(test_sensor_accepts_voltage_at_adc_range_boundaries);
    return UNITY_END();
}
