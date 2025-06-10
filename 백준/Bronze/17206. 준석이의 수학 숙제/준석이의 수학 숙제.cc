#include <iostream>
using namespace std;

typedef long long ll;
ll dp3[80'001];
ll dp7[80'001];
ll dp21[80'001];

ll DP3(ll N)
{
	if (N <= 0) return 0;
	if (dp3[N] != 0) return dp3[N];

	return dp3[N] = N + DP3(N - 3LL);
}

ll DP7(ll N)
{
	if (N <= 0) return 0;
	if (dp7[N] != 0) return dp7[N];

	return dp7[N] = N + DP7(N - 7LL);
}

ll DP21(ll N)
{
	if (N <= 0) return 0;
	if (dp21[N] != 0) return dp21[N];

	return dp21[N] = N + DP21(N - 21LL);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	ll N;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		cout << DP3(N - N % 3LL) + DP7(N - N % 7LL) - DP21(N - N % 21LL) << '\n';
	}

	return 0;
}