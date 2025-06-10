#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cout.precision(1); cout << fixed;

	long double ans = 0;
	int N; cin >> N;
	vector<long double> x(N), y(N);
	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < N; i++)
	{
		int j = (i + 1) % N;
		ans += x[i] * y[j] - x[j] * y[i];
	}
	ans = fabsl(ans);
	ans /= 2.0L;
	cout << ans;

	return 0;
}