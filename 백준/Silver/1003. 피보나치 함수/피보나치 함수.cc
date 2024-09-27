#include <iostream>
using namespace std;

int dp0[41] = { 0, };
int dp1[41] = { 0, };

int fibonacci0(int n)
{
    if (n <= 2) return dp0[n];
    else return dp0[n] = dp0[n - 1] + dp0[n - 2];
}

int fibonacci1(int n)
{
    if (n <= 2) return dp1[n];
    else return dp1[n] = dp1[n - 1] + dp1[n - 2];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    dp0[0] = dp0[2] = dp1[1] = dp1[2] = 1;
    dp0[1] = dp1[0] = 0;

    for (int i = 0; i < 41; i++)
    {
        dp0[i] = fibonacci0(i);
        dp1[i] = fibonacci1(i);
    }

    for (int i = 0; i < T; i++)
    {
        int num; cin >> num;
        cout << dp0[num] << " " << dp1[num] << "\n";
    }

    return 0;
}
