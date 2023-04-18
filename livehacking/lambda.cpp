#include <iostream>
#include <functional>
using namespace std;


// >>> def create_print(msg):
// ...     def doit():
// ...             print(msg)
// ...     return doit
// ... 

// >>> joerg = create_print("joerg")
// >>> joerg()

function<void()> create_print(string msg)
{
    auto doit = [msg](){
        cout << msg << endl;
    };
    return doit;
}

int main()
{
    auto joerg = create_print("joerg");

    joerg();

    return 0;
}
