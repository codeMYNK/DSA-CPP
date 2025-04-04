/*
Encapsulation : It simply refers to the strategy of Data Hiding. We encapsulate our data in a wrapper which here in this case is a
class.

Perfect Encapsulation is a stage where every data member is private and is accessed by their suitable getter and setter functions.

Advantages of Encapsulation :
1. We make our data more secure
2. We can make our class read-only
3. Data Reusability


Below example is of Perfect Encapsulation:
*/

#include <iostream>

using namespace std;

class Car
{
private:
    int cost;
    string name;
    string color;
    int currSpeed;

public:
    Car() // Constructor to initialise default data values
    {
        (*this).cost = 0;
        (*this).name = "abc";
        (*this).color = "xyz";
        (*this).currSpeed = 0;
    }

    // setter and getter functions to allow the access for data
    void setCost(int cost)
    {
        (*this).cost = cost;
    }

    void setName(string name)
    {
        (*this).name = name;
    }

    void setColor(string color)
    {
        (*this).color = color;
    }

    void setCurrSpeed(int currSpeed)
    {
        (*this).currSpeed = currSpeed;
    }

    int getCost()
    {
        return cost;
    }

    string getName()
    {
        return name;
    }

    string getColor()
    {
        return color;
    }

    int getCurrSpeed()
    {
        return currSpeed;
    }

    // deconstructor function to free the memory
    ~Car()
    {
        cout << "Memory freed successfully!" << endl;
    }
};

int main()
{
    Car *firstCar = new Car;
    // Setting data through Setters
    (*firstCar).setName("BMW M311 GTR");
    (*firstCar).setColor("White and Blue");
    (*firstCar).setCost(450000);
    (*firstCar).setCurrSpeed(150);

    // Getting data through getters
    cout << firstCar->getName() << endl;
    cout << firstCar->getColor() << endl;
    cout << firstCar->getCurrSpeed() << endl;
    cout << firstCar->getCost() << endl;

    delete (firstCar);
    return 0;
}
