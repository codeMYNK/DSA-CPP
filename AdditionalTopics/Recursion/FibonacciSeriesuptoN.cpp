#include <iostream>

using namespace std;

void printSeries(int n, int a = 0, int b = 1)
{
    if (n == 0)
    {
        return;
    }
    cout << a << " ";
    printSeries(n - 1, b, a + b);
}

int main()
{
    int userInput;

    cout << "Enter the max limit of the series: ";
    cin >> userInput;

    printSeries(userInput);
    cout << endl;
}