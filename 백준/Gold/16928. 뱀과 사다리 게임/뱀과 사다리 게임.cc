#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 101;
int adj[MAX];
queue<int> Q;
int diceCnt[101];
bool visit[MAX];
void BFS(int start)
{
    Q.push(start);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int next = cur + i;
            if (next == 100)
            {
                diceCnt[100] = diceCnt[cur] + 1;
                return;
            }

            while(adj[next]!=0)
            {
                next = adj[next];
            }
            if (!visit[next])
            {
                diceCnt[next] = diceCnt[cur] + 1;
                Q.push(next);
                visit[next] = true;
            }
        }

    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    int cnt = N + M;
    for (int i = 0; i < cnt; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x] = y;
    }
    memset(diceCnt, -1, sizeof(diceCnt));
    diceCnt[1] = 0;
    BFS(1);
    cout << diceCnt[100];
    return 0;
}