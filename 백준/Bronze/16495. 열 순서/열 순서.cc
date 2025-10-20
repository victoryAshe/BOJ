#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	int len = s.length();
	ll ans = 0;
	for (int i = len-1; i >=0; i--)
	{
		ll val = s[i] - 'A' + 1;
		ans += val * pow(26, len - i-1);
	}
	cout << ans;

	return 0;
}