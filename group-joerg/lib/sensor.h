#pragma once

class Sensor
{
public:
    Sensor(double temperature)
    {
        _temperature = temperature;
    }

    double get_temperature() const
    {
        return _temperature;
    }

private:
    double _temperature;
};
