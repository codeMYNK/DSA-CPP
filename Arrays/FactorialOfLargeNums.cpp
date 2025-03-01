#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userNum;
    cout << "Enter the number : ";
    cin >> userNum;

    vector<int> resultStore;
    resultStore.push_back(1);

    for (int num = 2; num <= userNum; num++)
    {
        int carry = 0;
        for (int i = 0; i < resultStore.size(); i++)
        {
            int prod = resultStore[i] * num + carry;
            resultStore[i] = prod % 10;
            carry = prod / 10;
        }

        while (carry)
        {
            resultStore.push_back(carry % 10);
            carry /= 10;
        }
    }

    cout << "The factorial of the input is: " << endl;

    for (int i = resultStore.size() - 1; i >= 0; i--)
    {
        cout << resultStore[i];
    }
}