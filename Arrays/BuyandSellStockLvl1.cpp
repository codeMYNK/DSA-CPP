#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int arrayLength;
    cout << "Enter the number of days : ";
    cin >> arrayLength;

    vector<int> stockArr(arrayLength);
    cout << "Enter the stock prices : " << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> stockArr[i];
    }

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < arrayLength; i++)
    {

        if (stockArr[i] < minPrice)
        {
            minPrice = stockArr[i];
        }

        int profit = stockArr[i] - minPrice;
        if (profit > maxProfit)
        {
            maxProfit = profit;
        }
    }

    cout << "The max profit on this share in the given number of days is : " << maxProfit << endl;
}
