#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool checkAllocation(const vector<int> &arr, int end, int totalStudents)
{
    int currStudent = 1, currPage = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] + currPage > end)
        {
            currStudent++;
            currPage = arr[i];
            if (currStudent > totalStudents)
            {
                return false;
            }
        }
        else
        {
            currPage = currPage + arr[i];
        }
    }
    return true;
}
int findMinMaxPages(const vector<int> &arr, int totalStudents)
{
    int start = *max_element(arr.begin(), arr.end());
    int end = accumulate(arr.begin(), arr.end(), 0);
    int result = end;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (checkAllocation(arr, mid, totalStudents))
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
    int booksArrLength, noOfStudents;
    cout << "Enter the number of books : ";
    cin >> booksArrLength;

    cout << "Enter the number of students : ";
    cin >> noOfStudents;

    vector<int> bookPagesArr(booksArrLength);
    cout << "Enter the pages in each book : ";
    for (int i = 0; i < booksArrLength; i++)
    {
        cin >> bookPagesArr[i];
    }
    int minMaxPages = findMinMaxPages(bookPagesArr, noOfStudents);

    if (minMaxPages == -1)
    {
        cout << "The book allocation is not possible : " << endl;
    }
    else
    {
        cout << "The minimum no of maximum pages that can be given to a student are : " << minMaxPages << " pages." << endl;
    }
}