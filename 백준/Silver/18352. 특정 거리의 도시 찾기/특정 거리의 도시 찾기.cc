#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 300001;
bool visit[MAX];
vector<int> adj[MAX];
int dist[MAX];

int N, M, K, X; // 노드 개수, 간선 개수, 출력해야하는 거리 정보, 출발 index

void BFS()
{
    queue<int> Q;
    Q.push(X);
    visit[X] = true;
    dist[X] = 0;

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
                dist[next] = dist[cur] + 1;
                Q.push(next);
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K >> X;

    // 간선 정보 입력
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
    }

    memset(dist, -1, sizeof(dist));
    BFS();

    vector<int> result;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == K) result.push_back(i);
    }
    if (result.size() == 0) cout << -1;
    else for (int x : result) cout << x << "\n";

    return 0;
}