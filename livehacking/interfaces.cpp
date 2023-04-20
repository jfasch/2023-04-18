#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Sensor
{
public:
    Sensor(const std::string& name)
    : name(name) {}
    virtual ~Sensor() {}
    virtual double get_temperature()
    {
        assert(false);
        return 666;
    }

    const std::string name;
};

class I2CSensor : public Sensor
{
public:
    I2CSensor(const std::string& name)
    : Sensor(name)
    {
        i2cmem = new char[1024];
    }
    ~I2CSensor()
    {
        cout << "~I2CSensor()" << endl;
        delete[] i2cmem;
    }

    double get_temperature()
    {
        return 42;
    }

private:
    char* i2cmem;
};

class OneWireSensor : public Sensor
{
public:
    OneWireSensor(const std::string& name)
    : Sensor(name)
    {
        owmem = new char[1024];
    }
    ~OneWireSensor()
    {
        cout << "~OneWireSensor()" << endl;
        delete[] owmem;
    }

    double get_temperature()
    {
        return -273.3;
    }

private:
    char* owmem;
};


int main()
{
    Sensor* s1 = new OneWireSensor("mein-ow-sensor");
    Sensor* s2 = new I2CSensor("mein-i2c-sensor");

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
