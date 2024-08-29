#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        size_t len = s.length();
        for (int j = 0; j < len; j++)
        {
            if (s[j] < 'a') s[j] += 32;
        }
        cout << s << "\n";
    }


    return 0;
}