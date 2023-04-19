#include "sensor-registry.h"


void SensorRegistry::add_sensor(std::string name, Sensor* s)
{
    _sensors[name] = s;
}

double SensorRegistry::get_temperature(std::string name) const
{
    return _sensors.at(name)->get_temperature();
}
