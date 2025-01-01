#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int drawingCnt = 0, largestArea = 0;

bool board[501][501];
bool visit[501][501];

pair<int, int> dir[4] = { {-1,0},{1,0},{0,-1},{0,1} };

int DFS(pair<int, int> p, int curArea)
{
    int i = p.first, j = p.second;
    visit[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
        int nextI = i + dir[k].first;
        int nextJ = j + dir[k].second;
        if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m) continue;

        if (board[nextI][nextJ] && !visit[nextI][nextJ])
        {
            curArea += DFS({ nextI, nextJ }, 1);
        }
    }
    return curArea;
}

int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] && !visit[i][j])
            {
                largestArea = max(largestArea, DFS({ i,j }, 1));
                drawingCnt++;
            }
        }
    }
    cout << drawingCnt << "\n" << largestArea;

    return 0;
}