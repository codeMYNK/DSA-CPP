#include <iostream>

using namespace std;

void straightCountingPrinter(int n)
{
    if (n == 0)
    {
        return;
    }
    straightCountingPrinter(n - 1);
    cout << n << " ";
}

void reverseCountingPrinter(int n)
{
    if (n == 0)
    {
        return;
    }

    cout << n << " ";
    reverseCountingPrinter(n - 1);
}

int main()
{
    int userLimit;

    cout << "Enter till when and till from you want to print counting : ";
    cin >> userLimit;

    cout << "Here is your straight counting upto the limit you have provided : " << endl;
    straightCountingPrinter(userLimit);

    cout << endl
         << "Here is your reverse counting upto the limit you have provided : " << endl;
    reverseCountingPrinter(userLimit);

    return 0;
}