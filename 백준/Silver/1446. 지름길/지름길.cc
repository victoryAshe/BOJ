#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10'001;
long dist[MAX];
vector<pair<int,int>> adj[MAX];

void CalcDist(long& d, long val)
{
    if (d == 0) d = val;
    else d = min(d, val);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, D;
    cin >> N >> D;

    int start, end, d;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end >> d;
        if (end > D) continue;
        adj[start].push_back({ end, d });
    }

    for (start = 0; start <= D; start++)
    {
        if (start > 0)
        {
            CalcDist(dist[start], dist[start - 1] + 1);
        }

        for (auto p : adj[start])
        {
            end = p.first, d = p.second;
            CalcDist(dist[end], dist[start] + d);

            dist[D] = min(dist[D], dist[end] + D - end);
        }
    }

    cout << dist[D];
    return 0;
}
