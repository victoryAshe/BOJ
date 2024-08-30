#include <iostream>
using namespace std;

int main()
{
    string biggestName, currName;
    int biggestNum = 0, currNum;
    for (int i = 0; i < 7; i++)
    {
        cin >> currName >> currNum;
        if (currNum > biggestNum)
        {
            biggestNum = currNum;
            biggestName = currName;
        }
    }
    cout << biggestName;

    return 0;
}