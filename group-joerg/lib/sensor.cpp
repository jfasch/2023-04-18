#include "sensor.h"

Sensor::Sensor(double temperature)
{
    _temperature = temperature;
}

double Sensor::get_temperature() const
{
    return _temperature;
}
