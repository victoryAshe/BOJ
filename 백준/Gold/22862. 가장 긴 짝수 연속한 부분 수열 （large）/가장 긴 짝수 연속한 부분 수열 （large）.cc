#include <iostream>
#include <cmath>
using namespace std;

int num[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	int N, K; cin >> N >> K;
	int maxLength = 0;

	for (int i = 0; i < N; i++) cin >> num[i];

	int left = 0, right = 0, oddCnt = 0;
	while (right < N)
	{
		if (num[right] % 2 == 1) oddCnt++;

		while (oddCnt > K)
		{
			if (num[left] % 2 == 1)oddCnt--;
			left++;
		}
		maxLength = max(maxLength, right - left + 1 - oddCnt);
		right++;
	}

	cout << maxLength;
	return 0;
}