#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Solution()
{
	int N; cin >> N;

	vector<int> L(N);
	for (int i = 0; i < N; i++) cin >> L[i];
	sort(L.begin(), L.end());

	int score = 0, cnt = N - 2;
	for (int i = 0; i < cnt; i++)
	{
		score = max(score, abs(L[i] - L[i + 2]));
	}

	cout << score << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	for (int t = 0; t < T; t++) Solution();

	return 0;
}