#include <vector>
#include <iostream>

using namespace std;

int main()
{
    const vector<int> v = {1, 2, 3};
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // for (size_t i=0; i<v.size(); i++)
    //     cout << v[i] << endl;
    // for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    //     cout << *it << endl;

    for (int elem: v)
        cout << elem << endl;

    return 0;
}
