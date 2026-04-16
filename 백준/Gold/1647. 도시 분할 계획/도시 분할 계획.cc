#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 100'001;
int parent[MAX];
int depth[MAX];

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Merge(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v) return;

    if (depth[u] > depth[v]) std::swap(u, v);
    parent[u] = v;
    if (depth[u] == depth[v]) depth[v]++;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) parent[i] = i;

    memset(depth, 1, sizeof(int) * (N + 1));

    priority_queue<pair<int, pair<int, int>>> PQ;
  
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        PQ.push({ -C, {A, B} });
    }

    int ans = 0, lastCost = 0;
    while (!PQ.empty())
    {
        int cost = -PQ.top().first;
        int u = PQ.top().second.first;
        int v = PQ.top().second.second;
        PQ.pop();

        if (Find(u) == Find(v)) continue;

        Merge(u, v);
        ans += cost;
        lastCost = cost;
    }
        
    std::cout << ans - lastCost;
    return 0;
}