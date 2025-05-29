#include <iostream>
using namespace std;

int main()
{
    string s; cin >> s;
    int num = 0;
    for (char c : s)
    {
        if (c - '0' == 0) num += 9;
        else num += c - '0';
    }
    cout << num;
    return 0;
}