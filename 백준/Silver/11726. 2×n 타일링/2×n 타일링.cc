#include <iostream>
using namespace std;

int dp[1001];

int DP(int x)
{
    if (x == 1) return 1;
    if (x == 2) return 2;
    if(dp[x]!=0) return dp[x];
    return dp[x] = (DP(x - 1)% 10007 + DP(x - 2) % 10007)%10007;
}

int main()
{
    int n; cin >> n;
    dp[1] = 1, dp[2] = 2;
    cout << DP(n);
    return 0;
}