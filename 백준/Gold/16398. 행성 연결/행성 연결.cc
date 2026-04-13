#include <iostream>
#include <queue>
#include <cstring>

// #16398

const int MAX = 1'001;

using ll = long long;
using CostEdge = std::pair<ll, std::pair<int, int>>;

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
    if (depth[u] == depth[v]) depth[v] += 1;
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    
    int N; 
    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    memset(depth, 1, sizeof(int) * (N+1));

    std::priority_queue<CostEdge> PQ;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            ll cost;
            std::cin >> cost;
            if (cost == 0|| j<i+1) continue;
            PQ.push({ -cost ,{i, j}});
        }
    }

    ll answer = 0;
    while (!PQ.empty())
    {
        ll cost = -PQ.top().first;
        int u = PQ.top().second.first;
        int v = PQ.top().second.second;
        PQ.pop();

        if (Find(u) == Find(v)) continue;
        Merge(u, v);
        answer += cost;
    }
    std::cout << answer;

    return 0;
}