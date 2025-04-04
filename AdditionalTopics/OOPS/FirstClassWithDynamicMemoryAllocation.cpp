#include <iostream>

using namespace std;
class Animal
{
private:
    int weight;
    int sleepHours;

public:
    int age;
    string type;

    // default constructer used to initialise our states
    Animal()
    {
        (*this).age = 0;
        (*this).type = "randomAnimal";
        (*this).weight = 0;
    }

    // Parametrized Constructer
    Animal(int sleepHours)
    {
        (*this).sleepHours = sleepHours;
    }

    // Copy Constructor : is called whenever we want to copy object

    Animal(Animal &obj)
    {
        (*this).age = obj.age;
        (*this).type = obj.type;
        (*this).weight = obj.weight;
        (*this).sleepHours = obj.sleepHours;
    }

    int getWeight()
    {
        return weight;
    }
    void setWeight(int weight)
    {
        (*this).weight = weight;
    }
    int getSleepHours()
    {
        return sleepHours;
    }

    // Destructor
    ~Animal()
    {
        cout << "Deleted" << endl;
    }
};

int main()
{
    Animal *tom = new Animal(4);
    (*tom).age = 15;
    (*tom).type = "Cat";
    (*tom).setWeight(10);

    Animal *tommy(tom);

    cout << tom->age << endl;
    cout << tom->type << endl;
    cout << tom->getWeight() << endl;
    cout << tom->getSleepHours() << endl;
    cout << endl;
    cout << tommy->age << endl;
    cout << tommy->type << endl;
    cout << tommy->getWeight() << endl;
    cout << tommy->getSleepHours() << endl;

    delete (tom);
    delete (tommy);

    return 0;
}