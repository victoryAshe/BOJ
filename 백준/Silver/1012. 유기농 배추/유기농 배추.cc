#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

bool visit[51][51];
vector<pair<int, int>> adj[51][51];
queue<pair<int, int>> Q;


void Solution()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < 51; i++) for (int j = 0; j < 51; j++) adj[i][j] = {};
    int result = 0;
    int N, M, K;
    cin >> M >> N >> K;
    for (int i = 1; i <= K; i++)
    {
        int x, y;
        cin >> x >> y; 
        if (x > 0) adj[y][x].push_back(make_pair(y, x - 1));
        if (x < M - 1) adj[y][x].push_back(make_pair(y, x + 1));
        if (y > 0) adj[y][x].push_back(make_pair(y - 1, x));
        if (y < N - 1) adj[y][x].push_back(make_pair(y + 1, x));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (adj[i][j].size() == 0) continue;
            if (!visit[i][j])
            {
                Q.push(make_pair(i, j));
                
                visit[i][j] = true;

                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    vector<pair<int, int>> curAdj = adj[cur.first][cur.second];
                    int len = curAdj.size();
                    for (int k = 0; k < len; k++)
                    {
                        pair<int, int> next = curAdj[k];
                        if (!visit[next.first][next.second])
                        {
                            vector<pair<int, int>> nextAdj = adj[next.first][next.second];
                            if (nextAdj.size() == 0) continue;
                            auto it = find(nextAdj.begin(), nextAdj.end(), cur);
                            if (it == nextAdj.end()) continue;
                            Q.push(next);
                            visit[next.first][next.second] = true;
                        }
                    }
                }
                result++;
            }
        }
    }


    cout << result << "\n";
}

int main()
{
    int T; cin >> T;
    for (int i = 0; i < T; i++)
        Solution();
    return 0;
}