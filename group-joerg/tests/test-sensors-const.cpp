#include <gtest/gtest.h>

#include <sensor.h>
#include <sensor-registry.h>


TEST(sensors_const, sensor)
{
    const Sensor s(42.666);
    s.get_temperature();
}

TEST(sensors_const, sensor_registry)
{
    SensorRegistry reg;
    reg.add_sensor("foo", new Sensor(42.666));
    reg.get_temperature("foo");
}
