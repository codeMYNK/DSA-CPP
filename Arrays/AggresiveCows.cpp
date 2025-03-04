#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool validator(vector<int> &arr, int minDistance, int totalCows)
{
    int currStall = arr[0], currCow = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - currStall >= minDistance)
        {
            currCow++;
            currStall = arr[i];
            if (currCow == totalCows)
            {
                return true;
            }
        }
    }
    return false;
}

int findMaxInMin(vector<int> &arr, int totalCows)
{
    sort(arr.begin(), arr.end());
    int start = 1;
    int end = arr.back() - arr[0];
    int result = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (validator(arr, mid, totalCows))
        {
            result = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return result;
}

int main()
{
    int noOfCows, noOfStalls;

    cout << "Enter the No of Stalls : ";
    cin >> noOfStalls;

    vector<int> stallLengthArr(noOfStalls);

    cout << "Enter the length of each stall : " << endl;

    for (int i = 0; i < noOfStalls; i++)
    {
        cin >> stallLengthArr[i];
    }
    cout << "Enter the total no of Cows : ";
    cin >> noOfCows;

    int result = findMaxInMin(stallLengthArr, noOfCows);

    cout << "The minimum distance in which the distance between two cows is maximised is : " << result;
}