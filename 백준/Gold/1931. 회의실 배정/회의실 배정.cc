#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> schedule;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		schedule.push_back({ end, start });
	}

	sort(schedule.begin(), schedule.end());

	int time = schedule[0].first;
	int result = 1;
	for (int i = 1; i <= N; i++)
	{
		if (schedule[i].second >= time)
		{
			time = schedule[i].first;
			result++;
		}
	}
	
	cout << result;

	return 0;
}