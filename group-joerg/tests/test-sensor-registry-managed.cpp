#include <gtest/gtest.h>

#include <sensor-registry.h>
#include <memory>


TEST(sensors_managed, basic)
{
    SensorRegistry reg;
    auto s = std::make_shared<Sensor>(42.666);
    reg.add_sensor("foo", s);
}
