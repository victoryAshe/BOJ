#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    for (char &c : s)
    {
        if (islower(c)) c = toupper(c);
        else c = tolower(c);
    }

    cout << s;

    return 0;
}