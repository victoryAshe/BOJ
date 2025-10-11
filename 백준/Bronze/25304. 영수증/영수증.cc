#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll X, result = 0LL; cin >> X;
	int N; cin >> N;
	ll a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		result += a * b;
	}

	if (result == X) cout << "Yes";
	else cout << "No";

	return 0;
}