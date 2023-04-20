#include <iostream>
#include <sensor.h>
#include <sensor-registry.h>


int main()
{
    // config phase
    auto s1 = std::make_unique<Sensor>(42.666);
    auto s2 = std::make_unique<Sensor>(36.5);

    SensorRegistry registry;
    registry.add_sensor("links-oben", std::move(s1));
    registry.add_sensor("rechts-unten", std::move(s2));
    registry.add_sensor("foo", std::make_unique<Sensor>(3.2));

    // runtime phase
    std::cout << "links-oben: " << registry.get_temperature("links-oben") << std::endl;
    std::cout << "rechts-unten" << registry.get_temperature("rechts-unten") << std::endl;

    // VERBOTEN!!
    // std::cout << s1->get_temperature() << std::endl;  // <--- Segmentation fault (core dumped)

    return 0;
}
