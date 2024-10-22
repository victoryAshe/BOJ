#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool visit[1000001] = { false, };

bool comp(pair<int, int>& a, pair<int, int>& b)
{
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

int isOverlapped(pair<int, int>& a, pair<int, int>& b)
{
	if (b.first <= a.second && b.second <= a.second) return -1; // a에 b가 포함됨
	if (b.first <= a.second) return 1;// b가 a와 일부 겹침
	return 0; // 겹치지 않음
}

int len(int a, int b)
{
	return b - a > 0 ? b - a : -(b - a);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<int, int>> lines;
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		lines.push_back(make_pair(x, y));
	}

	sort(lines.begin(), lines.end(), comp);

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if (visit[i]) continue;
		pair<int, int> overlapTarget = lines[i];
		visit[i] = true;
		for (int j = i + 1; j < N; j++)
		{
			int overlapResult = isOverlapped(overlapTarget, lines[j]);
			if (overlapResult == 0) break;
			else if (overlapResult == 1)
			{
				if (overlapTarget.second < lines[j].second)
				{
					overlapTarget.second = lines[j].second;
				}
			}

			visit[j] = true;
		}
		result += len(overlapTarget.first, overlapTarget.second);
	}
	cout << result;

	return 0;
}