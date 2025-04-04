/*
Inheritance is the mechanism of inheriting peoperties from the parent/base class by the children class.

Types of Inheritance :
1. Single : There is one parent class and one child class.
2. Multi Level : There is one parent class , child class, grandchild class and so on
   inhertiting properties from the respective base class.  E.g. - Fruit(base) -> Mango(child) -> Alphonso(grandchild)
3. Multiple : The child class is inheriting properties from multiple base/parent classes.
4. Heirarchal :  Multiple child classes are inheriting properties from a single base/parent class.
5. Hybrid : Combining One or more than one of the above types.
*/

#include <iostream>

using namespace std;

class Animal
{
public:
    int age;
    int weight;
    string type;

    void introduce()
    {
        cout << "Hi I am " << this->type << " , I am " << this->age << " years old and my weight is : " << this->weight << endl;
    }
    ~Animal()
    {
        cout << "Memory freed!" << endl;
    }
};

class Dog : public Animal
{
};

int main()
{
    Dog *spike = new Dog;

    (*spike).age = 10;
    (*spike).weight = 30;
    (*spike).type = "Dog";

    (*spike).introduce();

    delete (spike);

    return 0;
}