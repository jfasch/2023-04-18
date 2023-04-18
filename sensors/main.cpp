#include <iostream>

int main()
{
#if 0
    // config phase
    SensorRegistry registry;
    registry.add_sensor("links-oben", new Sensor(42.666));
    registry.add_sensor("rechts-unten", new Sensor(36.5));

    // runtime phase
    std::cout << "links-oben: " << registry.get_temperature("links-oben") << std::endl;
    std::cout << "rechts-unten" << registry.get_temperature("rechts-unten") << std::endl;
#endif

    return 0;
}
