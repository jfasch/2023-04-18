#include <gtest/gtest.h>

#include <sensor.h>
#include <sensor-registry.h>


TEST(sensor_suite, basic)
{
    Sensor sensor(42.666);
    double value = sensor.get_temperature();

    ASSERT_FLOAT_EQ(value, 42.666);
}

TEST(sensor_suite, registry)
{
    SensorRegistry registry;

    auto s1 = std::make_shared<Sensor>(42.666);
    auto s2 = std::make_shared<Sensor>(36.5);

    registry.add_sensor("foo", s1);
    registry.add_sensor("bar", s2);

    double value = registry.get_temperature("foo");
    ASSERT_FLOAT_EQ(value, 42.666);
    value = registry.get_temperature("bar");
    ASSERT_FLOAT_EQ(value, 36.5);
}
