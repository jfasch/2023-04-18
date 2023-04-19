#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <sensor.h>
#include <sensor-registry.h>

using namespace std;

int main()
{
    using my_sensors = map<string, shared_ptr<Sensor>>;

    // std::shared_ptr<Sensor> s = std::shared_ptr<Sensor>(new Sensor(42.666));
    auto s = make_shared<Sensor>(42.666);

    my_sensors sensors;
    sensors["foo"] = s;
    
    cout << sensors["foo"]->get_temperature() << endl;
    cout << s->get_temperature() << endl;
    
    return 0;
}
