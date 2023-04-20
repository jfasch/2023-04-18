#pragma once

#include <map>
#include <string>
#include <memory>

#include "sensor.h"


class SensorRegistry
{
public:
    void add_sensor(const std::string& name, std::unique_ptr<Sensor>);
    double get_temperature(std::string name) const;

private:
    std::map<std::string, std::unique_ptr<Sensor>> _sensors;
};
