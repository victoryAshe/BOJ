#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool visit[1001];

void DFS(int cur)
{
    visit[cur] = true;
    cout << cur << " ";
    int size = adj[cur].size();
    for (int i = 0; i < size; i++)
    {
        int next = adj[cur][i];
        if (!visit[next]) DFS(next);
    }
}

void BFS(int start)
{
    memset(visit, false, sizeof(visit));
    queue<int> Q;

    visit[start] = true;
    Q.push(start);

    while (!Q.empty())
    {
        int cur = Q.front();
        cout << cur << " ";
        Q.pop();
        int size = adj[cur].size();
        for (int i = 0; i < size; i++)
        {
            int next = adj[cur][i];
            if (!visit[next])
            {
                Q.push(next);
                visit[next] = true;
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

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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