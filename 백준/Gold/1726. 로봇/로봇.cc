#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;
const int NINF = -1e9;

int M, N;
int times[101][101][5];

int Dir[5][2] = { {INF, INF}, {0,1}, {0,-1}, {1,0},{-1,0} };
int getTwice[5] = { INF, 2, 1, 4, 3 };

struct State {
	int y, x, dir;
};

queue<State> Q;

int CalcTime(State cur, int nextDir)
{
	if (nextDir != cur.dir)
		return (nextDir == getTwice[cur.dir] ? 2 : 1);
	return 0;
}

void BFS(State& start, State& end)
{
	Q.push(start);
	times[start.y][start.x][start.dir] = 0;
	
	while (!Q.empty())
	{
		State cur = Q.front();
		Q.pop();

		for (int i = 1; i <= 4; i++)
		{
			int ny = cur.y;
			int nx = cur.x;
			int nextTime = times[cur.y][cur.x][cur.dir] + (i!=0);
			
			for (int j = 1; j <= 4; j++)
			{
				if (i == j) continue;
				int turnedTime = nextTime + CalcTime(cur, j);
			}

			nextTime += CalcTime(cur, i);

			if (i == 0) continue;
			for (int j = 1; j <= 3; j++)
			{
				ny += Dir[i][0]; 
				nx += Dir[i][1];
				
				if (ny<1 || ny > M || nx<1 || nx>N) break;
				if (times[ny][nx][0] == NINF) break;
				if (times[ny][nx][i] > nextTime)
				{
					times[ny][nx][i] = nextTime;
					Q.push({ ny,nx,i });
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= 4; i++)
	{
		if (times[end.y][end.x][i] != INF)
			ans = min(ans, times[end.y][end.x][i] + CalcTime({ end.y,end.x,i }, end.dir));
	}

	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		bool isNotRoute;
		for (int j = 1; j <= N; j++)
		{
			cin >> isNotRoute;
			if (isNotRoute) times[i][j][0] = NINF;
			else
			{
				for (int k = 0; k <= 4; k++) 
					times[i][j][k] = INF;
			}
		}
	}

	int y, x, dir;
	cin >> y >> x >> dir;
	State Start = { y,x,dir};
	cin >> y >> x >> dir;
	State End = { y,x,dir };

	BFS(Start, End);

	return 0;
}