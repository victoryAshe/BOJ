#include <iostream>
#include <cmath>
using namespace std;

void Solution()
{
	pair<int, int> start, end;
	int n;
	int startCnt = 0, endCnt = 0;

	cin >> start.first >> start.second >> end.first >> end.second >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> c; int r;
		cin >> c.first >> c.second >> r;
		int start_c = sqrt(pow(c.first - start.first, 2)+pow(c.second - start.second, 2));
		int end_c = sqrt(pow(c.first - end.first, 2) + pow(c.second - end.second, 2));
		if (start_c < r && end_c < r) continue;
		if (start_c < r) startCnt++;
		if (end_c < r) endCnt++;
	}
	cout << startCnt + endCnt << "\n";

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++) Solution();

	return 0;
}