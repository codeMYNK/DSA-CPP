#include <iostream>
#include <cmath>

using namespace std;

int binaryToDecimalConverter(int decimalNum)
{
    int binaryNo = 0;
    int i = 0;
    while (decimalNum > 0)
    {
        int bit = decimalNum % 2;
        binaryNo = bit * pow(10, i++) + binaryNo;
        decimalNum = decimalNum / 2;
    }
    return binaryNo;
}

int main()
{
    int userInput;

    cout << "Enter a number to convert into Binary : ";
    cin >> userInput;

    int result = binaryToDecimalConverter(userInput);

    cout << "The converted number is : " << result << endl;
}