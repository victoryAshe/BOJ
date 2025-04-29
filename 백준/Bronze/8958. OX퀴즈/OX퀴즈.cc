#include <iostream>
using namespace std;

void Solution()
{
    string s; cin >> s;
    int result = 0, cur = 0;
    for (char c : s)
    {
        if (c == 'O') cur++;
        else cur = 0;
        result += cur;
    }
    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        Solution();
    return 0;
}