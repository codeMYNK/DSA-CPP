#include <iostream>

using namespace std;

float areaCalc(int r)
{
    float area = 3.14 * r * r;
    return area;
}

int main()
{
    int userInput;

    cout << "Enter the radius of the circle : " << endl;
    cin >> userInput;

    float area = areaCalc(userInput);

    cout << "The area is : " << area << endl;
}