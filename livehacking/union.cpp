#include <iostream>
using namespace std;

enum Type {
    T_INT,
    T_FLOAT,
};

union foo {
    Type t;
    long int i;
    double f;
};

int main()
{
    foo f;
    f.f = -42.666;
    f.i = -666;

    cout << sizeof(foo) << ' ' << f.f << ' ' << f.i << endl;

    return 0;
};
