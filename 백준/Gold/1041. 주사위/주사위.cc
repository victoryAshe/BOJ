#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
const ll INF = 987654321;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;

    ll ans = 0;
    ll one, two, three;
    one = two = three = INF;

    ll dice[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i];
        one = min(one, dice[i]);
    }

    if (N == 1)
    {
        ll sideMax = 0;
        for (ll x : dice)
        {
            ans += x;
            sideMax = max(sideMax, x);
        }
        ans -= sideMax;
        cout << ans;
        return 0;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            if (i + j == 5) continue;
            
            ll cur2 = dice[i] + dice[j];
            two = min(two, cur2);

            for (int k = j + 1; k < 6; k++)
            {
                if (k + i == 5 || k + j == 5) continue;
                three = min(three, cur2 + dice[k]);
            }
        }
    }

    ll side0 = N > 2 ? (N-2)*(N-2)*(N-2) : 0,
        side2 = N >= 2 ? 8ll * N - 12ll : 0,
        side3 = N >= 2 ? 4ll : 0,
        side1 = N > 2 ? N*N*N -
        (side0 + side2 + side3 + (N-2)*(N-2)) : 0;

    ans = one * side1 + two * side2 + three * side3;
    cout << ans;

    return 0;
}