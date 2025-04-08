
/*
Polymorphism means that one entity existing in different forms. They are of 2 types:

1. Compile Time Polymorphism : It is achieved through function overloading, a state where we have
   multiple methods with the same name and the compiler determines which methods to call acoording to the suitable
   arguments.

2. Run time Polymorphism(Dynamic Binding) : It is an occuence of polymorphism during the program execution.
   Commonly done by using the virtual keyword in front of the function to pick the desired function
*/

#include <iostream>

using namespace std;

class Math
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        return a + b + c;
    }

    int sum(int a, float b)
    {
        return a + b;
    }

    ~Math()
    {
        cout << "Memory freed successfully." << endl;
    }
};

int main()
{
    Math *obj = new Math;

    cout << obj->sum(45, 50) << endl;

    delete obj;

    return 0;
}