#include <unity.h>

#include "../../src/drivers/temperature_sensor.h"
#include <utility>
#include <vector>

class MockTemperatureSensor : public Drivers::TemperatureSensor
{
    public:

        MockTemperatureSensor()
            : TemperatureSensor()
        {
        }

        void SetReadings(std::vector<int16_t> readings)
        {
            _readings = std::move(readings);
            _nextReading = 0;
        }

    protected:

        int16_t GetRawReading() override
        {
            return _readings.at(_nextReading++);
        }

    private:

        std::vector<int16_t> _readings;
        std::size_t _nextReading = 0;
};

void setUp(void) {}

void tearDown(void) {}

void test_sensor_converts_a_mocked_reading_to_celsius()
{
    MockTemperatureSensor sensor;
    sensor.SetReadings({400});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();

    TEST_ASSERT_FLOAT_WITHIN(0.001f, 25.0f, sensor.GetLastReading());
}

void test_sensor_averages_mocked_readings()
{
    MockTemperatureSensor sensor;
    sensor.SetReadings({400, 480});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();
    sensor.Update();

    TEST_ASSERT_FLOAT_WITHIN(0.001f, 27.5f, sensor.GetLastReading());
}

void test_readings_below_ten_celsius_and_error_values_are_ignored()
{
    MockTemperatureSensor sensor;
    sensor.SetReadings({400, 159, -160, 0, -1, 480});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();
    sensor.Update();
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 25.0f, sensor.GetLastReading());

    sensor.Update();
    sensor.Update();
    sensor.Update();
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 25.0f, sensor.GetLastReading());

    sensor.Update();
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 27.5f, sensor.GetLastReading());
}

void test_ten_degrees_is_accepted()
{
    MockTemperatureSensor sensor;
    sensor.SetReadings({160});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();

    TEST_ASSERT_FLOAT_WITHIN(0.001f, 10.0f, sensor.GetLastReading());
}

void test_average_forgets_readings_older_than_twelve_samples()
{
    MockTemperatureSensor sensor;
    sensor.SetReadings({
        320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 320, 512
    });

    TEST_ASSERT_TRUE(sensor.Init());
    for (int i = 0; i < 12; ++i)
    {
        sensor.Update();
    }
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 20.0f, sensor.GetLastReading());

    sensor.Update();
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 21.0f, sensor.GetLastReading());
}

void test_sensor_clamps_result_to_maximum_temperature()
{
    MockTemperatureSensor sensor;
    sensor.SetReadings({2000});

    TEST_ASSERT_TRUE(sensor.Init());
    sensor.Update();

    TEST_ASSERT_FLOAT_WITHIN(0.001f, 85.0f, sensor.GetLastReading());
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    UNITY_BEGIN();
    RUN_TEST(test_sensor_converts_a_mocked_reading_to_celsius);
    RUN_TEST(test_sensor_averages_mocked_readings);
    RUN_TEST(test_readings_below_ten_celsius_and_error_values_are_ignored);
    RUN_TEST(test_ten_degrees_is_accepted);
    RUN_TEST(test_average_forgets_readings_older_than_twelve_samples);
    RUN_TEST(test_sensor_clamps_result_to_maximum_temperature);
    return UNITY_END();
}
