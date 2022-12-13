#include <iostream>
#include <string>
using namespace std;

int main()
{
    int result = 0;

    //input
    string s = "";
    getline(cin, s);

    //calculate
    int n = s.length();
    string temp = "";
    if (s[0] != ' ') result++;

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == ' ' && s[i] != ' ') 
            result++;
    }

    //return
    cout << result;

    return 0;
}