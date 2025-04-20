#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int userSize;

    cout << "Enter the length of the input array : ";
    cin >> userSize;

    vector<int> userArr(userSize);
    cout << "Enter the array elements : " << endl;

    for (int i = 0; i < userSize; i++)
    {
        cin >> userArr[i];
    }

    stack<int> s;
    s.push(-1);

    vector<int> finalAns(userSize);

    for (int i = 0; i < userSize; i++)
    {
        int curr = userArr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        finalAns[i] = s.top();
        s.push(curr);
    }

    cout << "The ans is : " << endl;

    for (int i = 0; i < userSize; i++)
    {
        cout << finalAns[i] << " ";
    }
    return 0;
}