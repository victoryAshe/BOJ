#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(NULL); 
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int cost[3];
    int dp[1001][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[2];
    }
    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
    return 0;
}