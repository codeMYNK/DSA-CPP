#include <iostream>

using namespace std;

int exponentCalc(int n)
{
    int ans = 0;
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 2;
    }
    ans = 2 * exponentCalc(n - 1);
    return ans;
}

int main()
{
    int userInput;

    cout << "Enter the power till you want to exponentiate 2 : ";
    cin >> userInput;

    int result = exponentCalc(userInput);

    cout << "The result is : " << result << endl;
}