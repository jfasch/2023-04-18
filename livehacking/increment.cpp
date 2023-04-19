#include <iostream>
using namespace std;

int main()
{
    int i = 42;

    cout << "pre-inc:  " << ++i << endl;
    cout << "      i:  " << i << endl;

    cout << "post-inc: " << i++ << endl;
    cout << "       i: " << i << endl;

    return 0;
}
