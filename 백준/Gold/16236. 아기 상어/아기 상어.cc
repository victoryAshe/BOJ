#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

const int MAX = 21;
const int INF = 987654321;

using P = std::pair<int, int>;
P nullPos = { -1,-1 };

int space[MAX][MAX];
int dist[MAX][MAX];

int N;
int curSize = 2;

int dy[4] = { -1,0 ,0,1 };
int dx[4] = { 0,-1,1,0 };


P FindFish(const P& Start)
{
    std::vector<P> resultPoses = {};

    memset(dist, -1, sizeof(dist));

    std::queue<P> Q;
    Q.push(Start);
    dist[Start.first][Start.second] = 0;

    int shortestDist = INF;

    while (!Q.empty())
    {
        int curY = Q.front().first;
        int curX = Q.front().second;

        int& curFishSize = space[curY][curX];
        int& curDist = dist[curY][curX];
        if (curFishSize > 0 && curFishSize < curSize 
            && curDist <= shortestDist)
        {
            if (curDist < shortestDist)
            {
                shortestDist = curDist;
                resultPoses.clear();
            }
            resultPoses.emplace_back(Q.front());
        }

        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (space[ny][nx] > curSize) continue;
            if (dist[ny][nx] > -1) continue;

            Q.push({ ny,nx });
            dist[ny][nx] = curDist + 1;

        }
    }

    sort(resultPoses.begin(), resultPoses.end());

    if (resultPoses.size() == 0) return nullPos;
    return resultPoses[0];
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int eatenCount = 0;
    int seconds = 0;

    // Input
    std::cin >> N;

    int sharkPosY = -1, sharkPosX = -1;


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> space[i][j];

            if (space[i][j] == 9)
            {
                sharkPosY = i;
                sharkPosX = j;

                space[i][j] = 0;
            }
        }
    }

    // Have a nice meal
    while (true)
    {
        P found = FindFish({ sharkPosY, sharkPosX });
        if (found == nullPos) break;
        
        eatenCount += 1;
        if (eatenCount == curSize)
        {
            curSize += 1;
            eatenCount = 0;
        }

        sharkPosY = found.first, sharkPosX = found.second;
        seconds += dist[sharkPosY][sharkPosX];
        space[sharkPosY][sharkPosX] = 0;
    }

    std::cout << seconds;
    return 0;
}