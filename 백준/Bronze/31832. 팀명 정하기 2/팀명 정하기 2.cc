#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    string s;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s.length() > 10) continue;

        int upper = 0, lower = 0, digit = 0;
        for (char c : s)
        {
            if (islower(c)) lower++;
            else if (isupper(c)) upper++;
            else if (isdigit(c)) digit++;
        }
        if (digit == s.length()) continue;
        if (lower >= upper) break;
    }

    cout << s;
    
    return 0;
}