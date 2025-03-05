#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userInputOne, userInputTwo;

    cout << "Enter the length of 1st Array : ";
    cin >> userInputOne;
    cout << "Enter the length of 2nd Array : ";
    cin >> userInputTwo;
    vector<int> unifiedArr;

    vector<int> arr1(userInputOne);

    cout << "Enter the elements of 1st Array: " << endl;

    for (int i = 0; i < userInputOne; i++)
    {
        cin >> arr1[i];
        unifiedArr.push_back(arr1[i]);
    }

    vector<int> arr2(userInputTwo);

    cout << "Enter the elements of 2nd Array: " << endl;

    for (int i = 0; i < userInputTwo; i++)
    {
        cin >> arr2[i];
        unifiedArr.push_back(arr2[i]);
    }

    cout << "The unified array is : ";

    for (int i = 0; i < unifiedArr.size(); i++)
    {
        cout << unifiedArr[i] << " ";
    }
}