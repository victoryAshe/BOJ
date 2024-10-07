#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1500001;
int T[MAX], P[MAX], dp[MAX];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, income = 0;
    cin >> N;
    for (int i = 1; i <= N+1; i++)
    {
        if(i<N+1)cin >> T[i] >> P[i];
        income = max(income, dp[i]);
        int incomeDay = i + T[i];
        if (incomeDay <= N + 1) dp[incomeDay] = max(dp[incomeDay], P[i] + income);
    }
    cout << income;

    return 0;
}