#include <iostream>

using ll = long long;
const int MAX = 100'001;
ll arr[MAX];
int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    ll N, K; std::cin >> N >> K;
    ll sum = 0; int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> arr[i];

        sum += arr[i];
        if (K < sum)
        {
            ans = i; break;
        }
    }

    if (ans == 0)
    {
        K -= sum; sum = 0;
        for (int i = N; i >= 1; i--)
        {
            sum += arr[i];
            if (K < sum)
            {
                ans = i; break;
            }
        }
    }

    std::cout << ans;

    return 0;
}