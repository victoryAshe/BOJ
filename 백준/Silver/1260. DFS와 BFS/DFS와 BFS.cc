#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1001;
bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;

void DFS(int cur)
{
    visit[cur] = true;
    cout << cur << " ";

    int size = adj[cur].size();
    for (int i = 0; i < size; i++)
    {
        int next = adj[cur][i];
        if (visit[next]) continue;
        DFS(next);
    }
}

void BFS(int start)
{
    memset(visit, false, sizeof(visit));
    visit[start] = true;
    cout << start << " ";
    Q.push(start);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        int size = adj[cur].size();
        for (int i = 0; i < size; i++)
        {
            int next = adj[cur][i];
            if (!visit[next])
            {
                Q.push(next);
                visit[next] = true;
                cout << next << " ";
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, V;
    cin >> N >> M >> V;

    // 간선 정보 입력
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    DFS(V);
    cout << "\n";
    BFS(V);

    return 0;
}