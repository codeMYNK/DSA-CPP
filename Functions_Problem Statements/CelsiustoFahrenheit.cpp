#include <iostream>

using namespace std;

double tempConverter(double currTemp)
{
    double convertedTemp = (currTemp * 1.8) + 32;
    return convertedTemp;
}

int main()
{
    double userTemp;

    cout << "Enter the temperature in Celsius : ";
    cin >> userTemp;

    double convertedTemp = tempConverter(userTemp);

    cout << "Converted Temperature is : " << convertedTemp << endl;
}