#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; i++)
    {
        string s; cin >> s;
        char c = s[0];
        int longgest = 1;
        int cnt = 1;
        for (int j = 1; j < 8; j++)
        {
            if (s[j] == c) cnt++;
            else
            {
                if (cnt > longgest) longgest = cnt;
                cnt = 1;
                c = s[j];
            }
        }
        if (cnt > longgest) longgest = cnt;
        cout << longgest << "\n";
    }

    return 0;
}