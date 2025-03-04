#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossibleSolution(vector<int> &arr, int maxTime, int totalRotis)
{
    int currRotis = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int Rank = arr[i], j = 1;
        int timeTaken = 0;

        while (true)
        {
            if (timeTaken + Rank * j <= maxTime)
            {
                currRotis++;
                timeTaken += j * Rank;
                j++;
            }
            else
            {
                break;
            }
        }
        if (currRotis >= totalRotis)
        {
            return true;
        }
    }
    return false;
}

int findMinOrderTime(vector<int> &arr, int totalRotis)
{
    int start = 0;
    int highestRank = *max_element(arr.begin(), arr.end());
    int end = highestRank * (totalRotis * (totalRotis + 1) / 2);

    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossibleSolution(arr, mid, totalRotis))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int numberOfRotis, numberOfCooks;

    cout << "Enter the number of Rotis you want to order : ";
    cin >> numberOfRotis;

    cout << "Enter the number of cooks available : ";
    cin >> numberOfCooks;

    vector<int> cookRanksArray(numberOfCooks);

    for (int i = 0; i < numberOfCooks; i++)
    {
        cin >> cookRanksArray[i];
    }

    cout << "The minimum time taken to complete your order of " << numberOfRotis << " rotis by " << numberOfCooks << "is " << findMinOrderTime(cookRanksArray, numberOfRotis) << " mins";
}