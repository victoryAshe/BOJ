#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    string code = s.substr(0, 5);
    int T; cin >> T;
    int ans = 0;
    for (int t = 0; t < T; t++)
    {
        cin >> s;
        if (s.substr(0, 5) == code) ans++;
    }
    cout << ans;

    return 0;
}