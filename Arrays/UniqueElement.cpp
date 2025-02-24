#include <iostream>
#include <vector>

using namespace std;

int findUnique(vector<int> arr)
{
    int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arrayLength;

    cout << "Enter the length of array : ";
    cin >> arrayLength;

    vector<int> arr(arrayLength);

    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int uniqueElement = findUnique(arr);

    cout << "The unique element is : " << uniqueElement << endl;
}