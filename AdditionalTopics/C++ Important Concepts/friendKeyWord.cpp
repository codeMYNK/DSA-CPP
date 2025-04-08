/*
friend is a keyword that is used to share information of a class that was previously hidden
*/

#include <iostream>

using namespace std;

class A
{
    int x;

public:
    A(int _val) : x(_val) {} // initialisation list

    int getX() const
    {
        return x;
    }

    void setX(int _val)
    {
        x = _val;
    }

    friend class B; // friend keyword
};

class B
{
public:
    void print(const A &a)
    {
        cout << a.x << endl;
    }
};

int main()
{

    A a(5);
    B b;
    b.print(a);

    return 0;
}