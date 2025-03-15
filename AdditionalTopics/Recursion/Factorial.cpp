#include <iostream>

using namespace std;

int findFactorial(int n)
{

    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * findFactorial(n - 1);
}

int main()
{
    int userInput;

    cout << "Enter the number you want to find the factorial for : ";
    cin >> userInput;

    int result = findFactorial(userInput);

    cout << "The factorial for your entered number is : " << result << endl;
}