#include "sensor-registry.h"


void SensorRegistry::add_sensor(std::string name, Sensor* s)
{
    _sensors[name] = s;
}

double SensorRegistry::get_temperature(std::string name)
{
    return _sensors[name]->get_temperature();
}
