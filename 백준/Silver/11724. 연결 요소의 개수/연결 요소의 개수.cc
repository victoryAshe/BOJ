#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;

int N, M;
int result = 0;

void BFS(int start)
{
    Q.push(start);
    visit[start] = true;
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
                visit[next] = true;
                Q.push(next);
            }
        }
    }
    result++;
    for (int i = 1; i <= N; i++)
    {
        if (!visit[i])
        {
            BFS(i);
            break;
        }
    }
}

int main()
{
    cin >> N >> M;

    // 간선 정보 입력
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(1);
    cout << result;
    return 0;
}