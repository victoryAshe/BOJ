#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using ld = long double;
using ll = unsigned long long;

// return T_k = k(k+1)/2 <= n
bool CheckValid(ll k, ll n)
{
	ll a = k, b = k + 1;

	if (a % 2 == 0) a /= 2; else b /= 2;
	return a <= (n / b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	
	while (T--)
	{
		ll n; cin >> n;

		ld root = sqrt((ld)1.0 + (ld)8.0 * (ld)n);
		ll k = (ll)((root - 1.0L) / 2.0L);

		while (!CheckValid(k, n)) --k;
		while (CheckValid(k + 1, n)) ++k;
		cout << k << '\n';
	}

	return 0;
}