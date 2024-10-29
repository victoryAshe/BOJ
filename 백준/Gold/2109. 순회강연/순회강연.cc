#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int result = 0;
	int day = 1;
	vector<pair<int, int>> lecture;
	priority_queue<int> PQ;
	for (int i = 0; i < n; i++)
	{
		int p, d;
		cin >> p >> d;
		lecture.push_back(make_pair(p, d));
	}
	sort(lecture.begin(), lecture.end(), comp);

	for (int i = 0; i < n; i++)
	{
		pair<int, int> cur = lecture[i];
		if (day <= cur.second)
		{
			PQ.push(-cur.first);
			day++;
		}
		else if (-PQ.top() < cur.first)
		{
			PQ.pop();
			PQ.push(-cur.first);
		}
	}
	while (!PQ.empty())
	{
		result += -PQ.top();
		PQ.pop();
	}
	cout << result;
	return 0;

}