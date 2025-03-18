#include <iostream>
#include <vector>

using namespace std;

bool ascendingChecker(vector<int> &x, int i)
{
    if (i == x.size() - 1)
    {
        return true;
    }

    if (x[i] >= x[i - 1] && (i > 0))
    {
        return ascendingChecker(x, i + 1);
    }
    else
    {
        return false;
    }
}

bool descendingChecker(vector<int> &x, int i)
{
    if (i == 0)
    {
        return true;
    }
    if (x[i] <= x[i - 1])
    {
        return descendingChecker(x, i - 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    int userLength;
    cout << "Enter the length of the array: ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the elements of the array : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }
    int asccounter = 1;
    int dsccounter = userLength - 1;

    bool ascendingResult = ascendingChecker(userArr, asccounter);
    bool descendingResult = descendingChecker(userArr, dsccounter);

    if (!ascendingResult && !descendingResult)
    {
        cout << "The input array is not sorted." << endl;
    }
    else if (ascendingResult)
    {
        cout << "The input array is sorted in ascending order." << endl;
    }
    else
    {
        cout << "The input array is sorted in descending order." << endl;
    }
    return 0;
}