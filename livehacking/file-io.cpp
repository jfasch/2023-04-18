#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    auto f = ifstream(argv[1]);
    int i;
    f >> i;

    cout << "good: " << f.good() << endl;
    cout << "bad: " << f.bad() << endl;
    cout << "fail: " << f.fail() << endl;
    
    cout << i << endl;

    return 0;
}
