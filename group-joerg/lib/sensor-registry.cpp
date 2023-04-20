#include "sensor-registry.h"


void SensorRegistry::add_sensor(const std::string& name, std::unique_ptr<Sensor> s)
{
    _sensors[name] = std::move(s);
}

double SensorRegistry::get_temperature(std::string name) const
{
    return _sensors.at(name)->get_temperature();
}
