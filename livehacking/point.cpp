#include <iostream>
using namespace std;


class point
{
public:
    point() { _x = 0; _y = 0; }
    point(int x, int y) { _x = x; _y = y; }

    int x() { return _x; }
    int y() { return _y; }

    void move(point vec)
    {
        _x += vec._x;
        _y += vec._y;
    }
    point& operator+=(point vec)
    {
        _x += vec._x;
        _y += vec._y;
        return *this;
    }

    bool equals(point other)
    {
        return _x == other._x && _y == other._y;
    }

    bool operator==(point rhs)
    {
        return _x == rhs._x && _y == rhs._y;
    }

    point operator+(point rhs)
    {
        return point(_x+rhs._x, _y+rhs._y);
    }

private:
    int _x;
    int _y;
};


int main()
{
    /*const jjj!!!*/point p(1,2);
    cout << '(' << p.x() << ',' << p.y() << ')' << endl;

    point p1;
    cout << '(' << p1.x() << ',' << p1.y() << ')' << endl;

    point vec(3,4);

    point p3 = p += vec;
    cout << '(' << p3.x() << ',' << p3.y() << ')' << endl;

    point p2(4,6);
    // if (p == p2)
    //     cout << "equal" << endl;
    if (p.operator==(p2))
        cout << "equal" << endl;

    // point p4 = p1 + p2;
    point p4 = p1.operator+(p2);
    cout << "p4: " << '(' << p4.x() << ',' << p4.y() << ')' << endl;

    return 0;
}
