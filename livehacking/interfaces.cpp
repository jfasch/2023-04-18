#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Sensor
{
public:
    virtual ~Sensor() {}
    virtual double get_temperature() = 0;
};

class I2CSensor : public Sensor
{
public:
    ~I2CSensor()
    {
        cout << "~I2CSensor()" << endl;
        delete[] i2cmem;
    }

    double get_temperature() override
    {
        return 42;
    }

private:
    char* i2cmem;
};

class OneWireSensor : public Sensor
{
public:
    ~OneWireSensor()
    {
        cout << "~OneWireSensor()" << endl;
        delete[] owmem;
    }

    double get_temperature() override
    {
        return -273.3;
    }

private:
    char* owmem;
};


int main()
{
    Sensor* s1 = new OneWireSensor;
    Sensor* s2 = new I2CSensor;

    std::vector<Sensor*> sensors = {s1, s2};

    auto num = sensors.size();
    double sum = 0;
    for (auto s: sensors)
        sum += s->get_temperature();
    
    cout << "Average temperature: " << sum/num << endl;

    for (auto s: sensors)
        delete s;

    return 0;
}
