#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll height[51];

bool CalcSlope(bool &hasHighest, ll &a_num, ll &a_den, ll &b_num, ll &b_den)
{
    bool seen = false;
    if (!hasHighest || a_num * b_den < b_num * a_den)
    {
        hasHighest = true;
        seen = true;
        a_num = b_num;
        a_den = b_den;
    }
    return seen;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;

    ll N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> height[i];
    }

    bool hasHighest;
    ll highest_num, highest_den;
    ll num, den;
    for (ll i = 1; i <= N; i++)
    {
        int seen = 0;

        // Draw Left
        hasHighest = false;
        highest_num = 0, highest_den = 1;
        for (ll j = i-1; j >= 1; j--)
        {
            num = height[j] - height[i];
            den = i - j;
            seen += CalcSlope(hasHighest, highest_num, highest_den, num, den);
        }

        // Draw Right
        hasHighest = false;
        highest_num = 0, highest_den = 1;
        for (ll j = i + 1; j <= N; j++)
        {
            num = height[j] - height[i];
            den = j - i;
            seen += CalcSlope(hasHighest, highest_num, highest_den, num, den);
        }

        ans = max(ans, seen);
    }

    cout << ans;

    return 0;
}