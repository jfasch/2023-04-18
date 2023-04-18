#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;


// class Sensor
// {
// public:
//     virtual Sensor() {}
//     virtual double get_temperature() = 0;
// };

// class TemperatureAcquisition
// {
// public:
//     void add_temp_source(std::string, std::function<double()>);

//     vector<pair<string,double>> acquire() { ... }
// private:
//     vector<std::function<double()>> _sources;
// };

// ....

// TemperatureAcquisition acq;
// OneWireSensor ows(...);
// acq.add_temp_source("links oben", [ows](){return ows.get_temperature();});






int square(int n) { return n*n; }

int main()
{
    vector<int> input = {1,2,3};
    vector<int> output;

    transform(input.begin(), input.end(),
              back_insert_iterator<vector<int>>(output), 
              [](int n)->float{return n*n;});

    for (auto elem: output)
        cout << elem << endl;
    
    // int a = 666;
    // auto func = [a](){};
    // cout << sizeof(func) << endl;
    return 0;
}
