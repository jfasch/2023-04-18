#include <iostream>
using namespace std;

void print_that(const char** begin, int howmany)
{
    for (int i=0; i<howmany; i++) {
        const char* current = begin[i];
        cout << current << endl;
    }
}


int main()
{
    const char* names[] = { "foo", "bar" };

    print_that(names, 2);

    return 0;
}
