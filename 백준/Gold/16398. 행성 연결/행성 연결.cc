#include <iostream>
#include <queue>

// #16398

const int MAX = 1'001;

using ll = long long;
using Edge = std::pair<ll, int>;

int Cost[MAX][MAX];
bool Visited[MAX];

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    
    int N; 
    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> Cost[i][j];
        }
    }

    std::priority_queue<Edge> PQ;
    PQ.push({ 0,1 });

    ll answer = 0;
    int count = 0;

    while (!PQ.empty() && count < N)
    {
        ll cost = -PQ.top().first;
        int cur = PQ.top().second;
        PQ.pop();

        if (Visited[cur]) continue;
        Visited[cur] = true;
        answer += cost;
        count += 1;

        for (int next = 1; next <= N; next++)
        {
            if (Visited[next] || cur == next) continue;
            PQ.push({ -Cost[cur][next], next });
        }
    }

    std::cout << answer;

    return 0;
}