#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int idx; string s;
    for (int i = 0; i < T; i++)
    {
        cin >> idx >> s;
        idx -= 1;
        if (idx == 0) cout << s.substr(1) << "\n";
        else if (idx == s.length() - 1)
        {
            cout << s.substr(0, idx) << "\n";
        }
        else
        {
            cout << s.substr(0, idx) << s.substr(idx + 1) << "\n";
        }
    }
    return 0;
}