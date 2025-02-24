#include <iostream>

using namespace std;

int setKthBit(int userNum, int K)
{
    int mask = 1 << K;
    int ans = userNum | mask;
    return ans;
}

int main()
{
    int userNum;
    int K;

    cout << "Enter the number: ";
    cin >> userNum;

    cout << "Enter the limit : ";
    cin >> K;

    int result = setKthBit(userNum, K);

    cout << "The result of the conversion is : " << result << endl;
}