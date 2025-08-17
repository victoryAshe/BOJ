#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt[27] = { 0, };

    string s;
    while(!cin.eof())
    {
        cin >> s;
        if (cin.eof()) break;

        for (char c : s)
        {
            cnt[c - 'a']++;
        }
    }

    pair<int, string> ans = { 0, "" };
    for (int i = 0; i <= 26; i++)
    {
        char c = i + 'a';
        if (cnt[i] > ans.first)
        {
            string s(1, c);
            ans = { cnt[i], s};
        }
        else if (cnt[i] == ans.first)
        {
            ans.second += c;
        }
    }

    cout << ans.second;
    
    return 0;
}