#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool isWall[1001][1001];
int dist[1001][1001][2];  // i,j, isWallBroken

struct State {
    int y, x, isWallBroken;
};

queue<State> Q;

int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

void BFS()
{
    Q.push({1, 1, 0});
    dist[1][1][false] = 1, dist[1][1][true] = 1;
    
    while (!Q.empty())
    {
        State cur = Q.front();
        Q.pop();
        int curDist = dist[cur.y][cur.x][cur.isWallBroken];

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dir[i][0];
            int nx = cur.x + dir[i][1];
            int isWallBroken = cur.isWallBroken;
            if (ny < 1 || ny > N || nx < 1 || nx > M ) continue;

            if (isWall[ny][nx])
            {
                if (!isWallBroken && dist[ny][nx][1] == 0)
                {
                    dist[ny][nx][true] = curDist + 1;
                    Q.push({ ny, nx, true });
                }
            }
            else
            {
                if (dist[ny][nx][isWallBroken] == 0)
                {
                    dist[ny][nx][isWallBroken] = curDist + 1;
                    Q.push({ ny,nx,isWallBroken });
                }
            }
        }
    }
    
    int lastDistUnbroken = dist[N][M][0];
    int lastDistBroken = dist[N][M][1];

    if (lastDistUnbroken == lastDistBroken && lastDistBroken == 0) cout << "-1";
    else
    {
        if (lastDistUnbroken == 0) cout << lastDistBroken;
        else if (lastDistBroken == 0) cout << lastDistUnbroken;
        else cout << min(lastDistUnbroken, lastDistBroken);
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string s; 
        cin >> s;

        for (int j = 0; j < M; j++)  isWall[i][j+1] = s[j] == '1';
    }

    BFS();

    return 0;
}