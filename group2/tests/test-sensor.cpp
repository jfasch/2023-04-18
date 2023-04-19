#include <gtest/gtest.h>

#include <dummy.h>

TEST(dummy_suite, dummy)
{
    dummy();
    FAIL();
}

/*
#include <sensor.h>


TEST(sensor_suite, basic)
{
    Sensor sensor(42.666);
    double value = sensor.get_temperature();

    ASSERT_FLOAT_EQ(value, 42.666);
}

TEST(sensor_suite, registry)
{
    SensorRegistry registry;

    registry.add_sensor("links-oben", new Sensor(42.666));
    registry.add_sensor("rechts-unten", new Sensor(36.5));

    double value = registry.get_temperature("links-oben");
    ASSERT_FLOAT_EQ(value, 42.666);
    value = registry.get_temperature("rechts-unten");
    ASSERT_FLOAT_EQ(value, 36.5);
}
*/

