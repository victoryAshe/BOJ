#include <iostream>

using ll = long long;

const int MOD = 1'000'000'000;

int dp[201][201]; // N, K

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int N, K; std::cin >> N >> K;
    
    for (int i = 1; i <= K; i++) dp[0][i] = 1;
    for (int i = 0; i <= N; i++) dp[i][1] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= K; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    std::cout << dp[N][K];

    return 0;
}