#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool num[11];
    memset(num, true, sizeof(num));

    string high = "high", low = "low";
    string dishonest = "Stan is dishonest\n", honest = "Stan may be honest\n";
    
    int ans; string s;
    while (true)
    {
        cin >> ans;
        if (ans == 0) break;
        
        cin >> s >> s;
        if (s == high)
        {
            for (int i = ans; i <= 10; i++) num[i] = false;
        }
        else if (s == low)
        {
            for (int i = ans; i > 0; i--) num[i] = false;
        }
        else
        {
            if (num[ans]) cout << honest;
            else cout << dishonest;

            memset(num, true, sizeof(num));
        }
    }

    return 0;
}