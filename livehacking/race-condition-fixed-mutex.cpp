#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

class SafeInteger
{
public:
    SafeInteger(unsigned long init = 0) { _value = init; }

    unsigned long operator++()
    {
        _lock.lock();
        _value++;
        _lock.unlock();
        
        return _value;
    }

    unsigned long operator++(int)
    {
        unsigned long rv = _value;

        _lock.lock();
        _value++;
        _lock.unlock();
        
        return rv;
    }

    operator unsigned long()
    {
        return _value;
    }

private:
    unsigned long _value;
    mutex _lock;
};


void increment(SafeInteger* num)
{
    for (int i=0; i<10000000; i++)
        (*num)++;
}

int main()
{
    SafeInteger the_number;

    auto t1 = thread(increment, &the_number);
    auto t2 = thread(increment, &the_number);

    t1.join();
    t2.join();

    cout << the_number << endl;
    return 0;
}
