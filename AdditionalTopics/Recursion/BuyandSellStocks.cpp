// Leetcode Problem No: 121 -Best Time to Buy and Sell Stock (Easy)

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void maxProfitFinder(vector<int> &arr, int i, int &minPrice, int &maxProfit)
{
    if (i == arr.size())
    {
        return;
    }
    if (arr[i] < minPrice)
    {
        minPrice = arr[i];
    }
    int todaysProfit = arr[i] - minPrice;
    if (todaysProfit > maxProfit)
    {
        maxProfit = todaysProfit;
    }

    maxProfitFinder(arr, i + 1, minPrice, maxProfit);
}

int main()
{
    int userLength;

    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the stock prices: " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    maxProfitFinder(userArr, 0, minPrice, maxProfit);

    cout << "The max profit is : " << maxProfit << endl;
}