#include <thread>
#include <atomic>
#include <iostream>

using namespace std;


void increment(atomic<unsigned long>* num)
{
    for (int i=0; i<10000000; i++)
        (*num)++;
}

int main()
{
    atomic<unsigned long> the_number;

    auto t1 = thread(increment, &the_number);
    auto t2 = thread(increment, &the_number);

    t1.join();
    t2.join();

    cout << the_number << endl;
    return 0;
}
