#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string ans = "";

    int K; string s;
    cin >> K >> s;
    int len = s.length();
    for (int i = 0; i < len; i += K)
    {
        ans += s[i];
    }
    
    cout << ans;

    return 0;
}