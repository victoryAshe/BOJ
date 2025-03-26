#include <iostream>
using namespace std;

const int MAX = 100001;
int num[MAX];
long long dp[2][MAX];
long long biggest = -1e9 -1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    dp[0][0] = dp[1][0] = biggest = num[0];
    for (int i = 1; i < n; i++)
    {
        long long prev = dp[0][i - 1], prevDel = dp[1][i - 1];
        long long added = prev + num[i], addedDel = prevDel + num[i];

        dp[0][i] = num[i] < added ? added : num[i];
        dp[1][i] = added < prev ? (prev < addedDel ? addedDel : prev) : addedDel;

        biggest = max(biggest, max(dp[0][i], dp[1][i]));
    }

    cout << biggest;

    return 0;
}