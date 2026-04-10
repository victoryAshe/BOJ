#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using ll = long long;
using Edge = std::pair<int, int>;

const int MAX = 10'001;
int parent[MAX];
int depth[MAX];

int FindParent(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = FindParent(parent[x]);
}

void Merge(int u, int v)
{
    u = FindParent(u);
    v = FindParent(v);
    if (u == v) return;

    if (depth[u] > depth[v]) std::swap(u, v);
    parent[u] = v;

    if (depth[u] == depth[v]) depth[v]++;
}


int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int V, E;
    std::cin >> V >> E;

    // Make Vertex's parent.
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
        depth[i] = 1;
    }

    ll answer = 0;
    std::priority_queue<std::pair<ll, Edge>> PQ;

    // Input Edges.
    for (int i = 0; i < E; i++)
    {
        Edge e; ll cost;
        std::cin >> e.first >> e.second >> cost;
        PQ.push({ -cost, e });
    }

    while (!PQ.empty())
    {
        ll cost = -PQ.top().first;
        int u = PQ.top().second.first;
        int v = PQ.top().second.second;
        PQ.pop();

        if (FindParent(u) == FindParent(v)) continue;

        Merge(u, v);
        answer += cost;
    }

    std::cout << answer;

    return 0;
}