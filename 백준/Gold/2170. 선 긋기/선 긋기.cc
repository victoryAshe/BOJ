#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> lines[1000000];

bool comp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

enum class OverlapState {
	겹치지않음, 
	일부겹침, 
	포함됨
};

OverlapState overlapResult(pair<int,int>& a, pair<int,int>& b)
{
	if (b.first <= a.second)
	{
		if (a.second <= b.second) return OverlapState::일부겹침;
		return OverlapState::포함됨;
	}
	else return OverlapState::겹치지않음;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int answer = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		lines[i] = make_pair(x, y);
	}
	sort(lines, lines + N, comp);
    
	pair<int, int> prevLine = lines[0];
	for (int i = 1; i < N; i++)
	{
		OverlapState state = overlapResult(prevLine, lines[i]);
		if (state == OverlapState::일부겹침)
		{
			prevLine.second = lines[i].second;
		}
		else if (state == OverlapState::겹치지않음)
		{
			answer += prevLine.second - prevLine.first;
			prevLine = lines[i];
		}
	}
	answer += prevLine.second - prevLine.first;
	cout << answer;
	return 0;
}