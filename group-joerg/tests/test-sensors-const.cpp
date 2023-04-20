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
    reg.add_sensor("foo", std::make_shared<Sensor>(42.666));
    const SensorRegistry* myconstreg = &reg;
    myconstreg->get_temperature("foo");
}
