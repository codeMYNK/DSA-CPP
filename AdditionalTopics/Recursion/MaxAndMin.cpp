#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxElementFinder(vector<int> &arr, int size)
{
    if (size == 1)
        return arr[0];
    return max(arr[size - 1], maxElementFinder(arr, size - 1));
}

int minElementFinder(vector<int> &arr, int size)
{
    if (size == 1)
        return arr[0];
    return min(arr[size - 1], minElementFinder(arr, size - 1));
}

int main()
{
    int userArrLength;

    cout << "Enter the length of the array: ";
    cin >> userArrLength;

    vector<int> userArr(userArrLength);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < userArrLength; i++)
    {
        cin >> userArr[i];
    }

    int maxElement = maxElementFinder(userArr, userArrLength);
    int minElement = minElementFinder(userArr, userArrLength);

    cout << "The max element is: " << maxElement << " and the min element is: " << minElement << endl;

    return 0;
}
