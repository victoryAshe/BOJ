#include <iostream>
#include <queue>
using namespace std;

bool nums[5001];

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int idx = 1, cnt = 0, deletedCnt = 0;
	cout << "<";
	while (deletedCnt < N)
	{
		if (nums[idx])
		{
			if (++idx > N) idx = 1;
			continue;
		}

		if (++cnt == K)
		{
			cout << idx;
			cnt = 0;
			nums[idx] = true;
			deletedCnt++;
			if (deletedCnt < N) cout << ", ";
			else cout << ">";
		}
		if (++idx > N) idx = 1;
	}

	return 0;
}