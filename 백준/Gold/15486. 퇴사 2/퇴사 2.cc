#include <iostream>
#include <cmath>
using namespace std;

int dp[1500001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, income = 0;
    cin >> N;
    for (int i = 1; i <= N+1; i++)
    {
        int t = 0, p = 0;
        if(i<N+1) cin >> t >> p;
        income = max(income, dp[i]);
        int incomeDay = i + t;
        if (incomeDay <= N + 1) dp[incomeDay] = max(dp[incomeDay], p + income);
    }
    cout << income;

    return 0;
}