#pragma once

class Sensor
{
public:
    Sensor(double temperature);
    double get_temperature() const;

private:
    double _temperature;
};
