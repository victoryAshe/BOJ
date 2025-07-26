#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int INF = 987654321;

int N;
int nums[1'001];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}
}

void Solution()
{
	unordered_map<int, vector<int>> team;
	unordered_map<int, int> team_score;
	unordered_map<int, int> team_left;

	int team_num;
	for (int rank = 1; rank <= N; rank++)
	{
		team_num = nums[rank];
		if (team.find(team_num) == team.end())
		{
			team[team_num] = { rank };
		}
		else team[team_num].push_back(rank);
	}

	int score = 1;
	for (int rank = 1; rank <= N; rank++)
	{
		team_num = nums[rank];
		if (team[team_num].size() < 6) continue;
		
		score++;
		if (team_score.find(team_num) == team_score.end())
		{
			team_score[team_num] = score;
			team_left[team_num] = 3;
		}
		else if (team_left[team_num] > 0)
		{
			team_score[team_num] += score;
			team_left[team_num]--;
		}
	}

	pair<int, vector<int>> candidates = { INF,{} };
	for (auto p : team_score)
	{
		int teamNum = p.first;
		int score = p.second;
		if (score < candidates.first)
		{
			candidates = { score, {teamNum} };
		}
		else if (score == candidates.first)
		{
			candidates.second.push_back(teamNum);
		}
	}

	if (candidates.second.size() == 1) cout << candidates.second[0]<<"\n";
	else
	{
		pair<int, int> fastest_fifth = { 0, INF };
		for (auto teamNum : candidates.second)
		{
			int cur_fifth = team[teamNum][4];
			
			if (cur_fifth < fastest_fifth.second)
			{
				fastest_fifth = { teamNum, cur_fifth };
			}
			
		}
		cout << fastest_fifth.first << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		Input();
		Solution();
	}

	return 0;
}