#include <iostream>
#include <vector>

using namespace std;

int numOfPairs(const vector<int> &arr, int length, int difference)
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        int start = 0;
        int end = i - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[i] - difference == arr[mid])
            {
                counter++;
                break;
            }
            else if (arr[mid] < arr[i] - difference)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return counter;
}

int main()
{
    int userLength;
    cout << "Enter the no of elements in the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);
    int userDiff;

    cout << "Enter the elements of array : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }
    cout << "Enter the difference you want to search for : ";
    cin >> userDiff;

    int result = numOfPairs(userArr, userLength, userDiff);

    if (result == 0)
    {
        cout << "No elements are equal to your desired difference.";
    }
    else
    {
        cout << "The number of pairs that will be equal to " << userDiff << " when subtracted are : " << result;
    }
}