#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long acidity[5000];
vector<long long> answer;
long long diff = 3000000001;
void search(int start, int end, long long target)
{
	int low = start, high = end;
	while (low < high)
	{
		long long sum = acidity[low] + acidity[high] + target;

		if (abs(sum) < diff)
		{
			diff = abs(sum);
			answer = { acidity[low], acidity[high], target };
		}

		if (sum < 0) low++;
		else if (sum > 0) high--;
		else break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> acidity[i];
	sort(acidity, acidity + N);

	for (int i = 0; i <= N - 3; i++) 
		search(i + 1, N - 1, acidity[i]);

	sort(answer.begin(), answer.end());
	for (int x : answer) cout << x << " ";

	return 0;
}