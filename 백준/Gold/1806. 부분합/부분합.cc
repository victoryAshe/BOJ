#include <iostream>
using namespace std;

const int MAX = 100'001;
int N, S;
int num[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> num[i];

	int ans = MAX;
	int start = 0, end = 0;
	int sum = num[0];
	while (start <= end && end < N)
	{
		if (sum >= S) ans = min(ans, end - start + 1);
		if (sum < S)
		{
			sum += num[++end];
		}
		else
		{
			sum -= num[start++];
		}
	}

	if (ans == MAX) cout << "0";
	else cout << ans;

	return 0;
}