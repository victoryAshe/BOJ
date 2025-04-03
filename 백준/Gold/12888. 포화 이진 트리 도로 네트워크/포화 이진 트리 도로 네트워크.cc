#include <iostream>
using namespace std;

long long ans[60] = {1, 1, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int H; cin >> H;
	for (int i = 2; i <= H; i++)
	{
		ans[i] = ans[i - 2] + (1LL <<(i-1));
	}

	cout << ans[H];

	return 0;
}