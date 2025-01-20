#include <iostream>
#include <algorithm>
using namespace std;

int A[10000];
int N;
long long answer = 0;

void bin_search(int start, int end, int target)
{
	int low = start, high = end;
	while (low <= high)
	{
		int sum = A[low] + A[high] + target;

		if (sum < 0) low++;
		else if (sum > 0) high--;
		else
		{
			if (A[low] == A[high])
			{
				answer += ((high - low) * (high - low + 1)) / 2;
				break;
			}

			int lowCnt = 1;
			while (low + 1 < high && A[low] == A[low + 1])
			{
				lowCnt++; low++;
			}

			int highCnt = 1;
			while (high - 1 > low && A[high] == A[high - 1])
			{
				highCnt++; high--;
			}

			answer += lowCnt * highCnt;
			low++;
			high--;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	sort(A, A + N);

	for (int i = 0; i <= N - 3; i++)
	{
		bin_search(i + 1, N - 1, A[i]);
	}
	cout << answer;
	return 0;
}