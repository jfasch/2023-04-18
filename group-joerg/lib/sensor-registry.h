#pragma once

#include <map>
#include <string>

#include "sensor.h"

class SensorRegistry
{
public:
    void add_sensor(std::string name, Sensor*);
    double get_temperature(std::string name);

private:
    std::map<std::string, Sensor*> _sensors;
};
