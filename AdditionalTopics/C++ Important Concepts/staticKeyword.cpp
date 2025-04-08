/*
Static data member : The variable is going to share the memory with all of the class instances.
Static member function : There is no instance of that class being passed into that method
*/

#include <iostream>

using namespace std;

class abc
{
public:
    static int x, y;

    void print() const
    {
        cout << x << " " << y << endl;
    }
};

int abc::x;
int abc::y;

int main()
{
    abc obj1;
    abc obj2;

    obj1.x = 5;
    obj1.y = 7;
    obj1.print();

    obj2.x = 10;
    obj2.y = 9;
    obj2.print();
    obj1.print();
    return 0;
}