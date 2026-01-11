#include <iostream>
#include <vector>
#include <queue>

const int MAX = 10'001;
std::vector<int> adj[MAX];

int mostTrust = 0;
std::vector<int> mostTrusted;

void BFS(int N, int start)
{
    std::vector<bool> visit(N + 1);
    std::queue<int> Q;
    
    Q.push(start);
    visit[start] = true;
    int curMostTrust = 0;

    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        curMostTrust += 1;

        for (int next : adj[cur])
        {
            if (!visit[next])
            {
                Q.push(next);
                visit[next] = true;
            }
        }
    }
    
    if (mostTrust < curMostTrust)
    {
        mostTrust = curMostTrust;
        mostTrusted = { start };
    }
    else if (mostTrust == curMostTrust)
    {
        mostTrusted.emplace_back(start);
    }
}

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N, M, A, B;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        std::cin >> A >> B;
        adj[B].emplace_back(A);
    }

    for (int i = 1; i <= N; i++)
    {
        BFS(N, i);
    }

    for (int x : mostTrusted) std::cout << x << " ";

    return 0;
}