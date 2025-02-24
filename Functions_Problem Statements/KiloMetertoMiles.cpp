#include <iostream>

using namespace std;

double ToMileConverter(int distanceInKm)
{
    double convertedDistance = distanceInKm * 0.6213;
    return convertedDistance;
}

int main()
{
    int userInput;

    cout << "Enter the distance in kilo-meters : ";
    cin >> userInput;

    double convertedDistance = ToMileConverter(userInput);

    cout << "The converted Distance is : " << convertedDistance << " miles" << endl;
}