#include <iostream>
#include <cstring>

const int MAX = 1'001;
const int MOD = 1'000'000;

// top-down
int N;
int dp[MAX][2][3];

int DP(int day, int late, int absent)
{
    if (late == 2) return 0;
    if (absent == 3) return 0;
    if (day > N) return 1;

    int& cache = dp[day][late][absent];
    if (cache != -1) return cache;

    return cache = (DP(day + 1, late, 0) 
        + DP(day + 1, late + 1, 0) 
        + DP(day + 1, late, absent + 1)) % MOD;
}

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    std::cin >> N;
    std::cout << DP(1,0,0);

    return 0;
}