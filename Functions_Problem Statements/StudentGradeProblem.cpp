#include <iostream>

using namespace std;

char studentGrade(int marks)
{
    if (marks >= 90)
    {
        return 'A';
    }
    else if (marks >= 80)
    {
        return 'B';
    }
    else if (marks >= 70)
    {
        return 'C';
    }
    else if (marks >= 60)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

int main()
{
    int marks;

    cout << "Please input your marks: " << endl;
    cin >> marks;

    char finalGrade = studentGrade(marks);

    cout << "Your grade for the subject is : " << finalGrade << endl;
}