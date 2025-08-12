#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int TopologySort(int N, vector<vector<int>>& adj, vector<int> &inDegree)
{
    int ans = 0;
    
    queue<int> Q;
    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0) Q.push(i);
    }

    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        ans++;
        for (int v : adj[u])
        {
            if (--inDegree[v] == 0) Q.push(v);
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> inDegree(N + 1);
    vector<vector<int>> adj(N + 1, vector<int>());
    int u, v;

    // 간선 뒤집어 넣기
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[v].push_back(u);
        inDegree[u]++;
    }

    int ans = TopologySort(N, adj, inDegree);

    cout << ans;

    return 0;
}