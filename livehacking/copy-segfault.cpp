#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    const vector<int> input = {1,2,3,4,5};
    vector<int> output(input.size());
    output.reserve(input.size());

    copy(input.begin(), input.end(), output.begin());

    cout << "output.size(): " << output.size() << endl;
    for (size_t i=0; i<output.size(); ++i)
        cout << output[i] << endl;

    return 0;
}
