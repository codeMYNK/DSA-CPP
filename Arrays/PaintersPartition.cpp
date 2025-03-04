#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool validator(const vector<int> &arr, int end, int totalPainters)
{
    int currPainter = 1, currTimetakentoPaint = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + currTimetakentoPaint > end)
        {
            currPainter++;
            currTimetakentoPaint = arr[i];
            if (currPainter > totalPainters)
            {
                return false;
            }
        }
        else
        {
            currTimetakentoPaint = currTimetakentoPaint + arr[i];
        }
    }
    return true;
}

int findMininMax(const vector<int> &arr, int totalPainters)
{
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int result = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (validator(arr, mid, totalPainters))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int main()
{
    int userLength, noOfPainters;

    cout << "Enter the number of Boards : ";
    cin >> userLength;

    vector<int> boardLengthArr(userLength);

    cout << "Enter the board lengths : " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> boardLengthArr[i];
    }

    cout << "Enter the number of painters : ";
    cin >> noOfPainters;

    int result = findMininMax(boardLengthArr, noOfPainters);
    cout << "The minimum of maximum time taken is : " << result << endl;
}