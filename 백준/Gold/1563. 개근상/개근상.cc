#include <iostream>

const int MAX = 1'001;
const int MOD = 1'000'000;

// bottom-up

int dp[MAX][2][3];
int CalcSum(int i)
{
    auto* cur = dp[i];
    int sum = 0;

    for (int L = 0; L < 2; L++)
        for (int A = 0; A < 3; A++)
            sum = (sum + cur[L][A]) % MOD;
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    auto* cur = dp[1];
    cur[0][0] = cur[0][1] = cur[1][0] = 1;

    int N;
    std::cin >> N;

    for (int i = 2; i <= N; i++)
    {
        cur = dp[i];
        auto* prev = dp[i - 1];
        cur[0][0] = (prev[0][0] + prev[0][1] + prev[0][2]) % MOD;
        cur[0][1] = prev[0][0];
        cur[0][2] = prev[0][1];

        cur[1][0] = CalcSum(i-1);
        cur[1][1] = prev[1][0];
        cur[1][2] = prev[1][1];
    }

    std::cout << CalcSum(N);

    return 0;
}