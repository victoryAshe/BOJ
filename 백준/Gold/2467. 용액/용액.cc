#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int N;
int diff = 2000000001;
pair<int, int> answer;

void bin_search(int start, int end, int target)
{
	int low = start, high = end;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int sum = A[mid] + target;

		if (sum < 0) low = mid + 1;
		else if (sum > 0) high = mid-1;

		if (abs(sum) < diff)
		{
			diff = abs(sum);
			answer = { target, A[mid] };
		}
		if (sum == 0) break;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	sort(A, A + N);

	for (int i = 0; i <N; i++)
	{
		bin_search(i + 1, N - 1, A[i]);
	}
	cout << answer.first << " " << answer.second;
	return 0;
}