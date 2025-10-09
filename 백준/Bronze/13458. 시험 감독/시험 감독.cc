#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	int B, C; cin >> B >> C;

	long long ans = N;
	for (int a : A)
	{
		if (a > B)
		{
			a -= B;
			ans += a / C;
			if (a % C > 0) ans++;
		}
	}

	cout << ans;

	return 0;
}