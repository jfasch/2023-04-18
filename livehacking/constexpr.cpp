#include <iostream>
#include <string>
using namespace std;

constexpr int a_random_integer(int a)
{
    return a + 666;
}

constexpr int blah = a_random_integer(42);

int main()
{
    cout << blah << endl;

    return 0;
}
