#include <iostream>

using namespace std;

class Math
{

public:
    int val;

    void operator+(Math &object2)
    {
        cout << object2.val - this->val << endl;
    }

    ~Math()
    {
        cout << "Memory Freed.";
    }
};

int main()
{

    Math *obj1 = new Math;
    Math *obj2 = new Math;

    obj1->val = 7;
    (*obj2).val = 5;

    (*obj1) + (*obj2);

    delete obj1, obj2;

    return 0;
}