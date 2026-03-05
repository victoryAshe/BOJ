#include <iostream>
#include <cstring>
#include <queue>

const int MAX = 1'001;
using Point = std::pair<int, int>;

int board[MAX][MAX];
int dist[MAX][MAX];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1, 0,0 };

int n, m;

void BFS(int startY, int startX)
{
    std::queue<Point> Q;
    Q.push({startY, startX});
    dist[startY][startX] = 0;

    while (!Q.empty())
    {
        int curY = Q.front().first;
        int curX = Q.front().second;
        int curCost = dist[curY][curX];
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];
            int nextCost = curCost + 1;
            if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m) continue;

            if(board[nextY][nextX] == 1 && dist[nextY][nextX] == -1)
            {
                dist[nextY][nextX] = nextCost;
                Q.push({nextY, nextX});
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    memset(dist, -1, sizeof(dist));
   
    std::cin >> n >> m;

    int startY = 0, startX = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 2)
            {
                startY = i, startX = j;
            }
        }
    }

    BFS(startY, startX);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int& cur = board[i][j];

            if (cur == 0) std::cout << "0 ";
            else std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}