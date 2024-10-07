#include <iostream>
#include <cmath>
using namespace std;
int dp[501][501];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    
    int largest = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> dp[i][j];
            if (j == 0) dp[i][j] += dp[i - 1][j];
            else if (j == i - 1) dp[i][j] += dp[i - 1][j - 1] ;
            else dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]) ;
            if (dp[i][j] > largest) largest = dp[i][j];
        }
    }
    cout << largest;
    return 0;
}