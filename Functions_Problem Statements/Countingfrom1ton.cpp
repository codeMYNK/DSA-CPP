#include <iostream>

using namespace std;

void countPrinter(int limit)
{
    for (int flag = 0; flag < limit; flag++)
    {
        cout << flag + 1 << " ";
    }
}

int main()
{
    int maxLimit;
    cout << "Enter the limit: " << endl;
    cin >> maxLimit;

    countPrinter(maxLimit);
}