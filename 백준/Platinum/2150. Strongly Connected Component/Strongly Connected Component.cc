#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

const int MAX = 10'001;
std::set<int> adj[MAX];

int num[MAX];
int low[MAX];
bool visit[MAX];
int sccCnt = 0;
std::stack<int> Stack;

std::vector<std::set<int>> ans;

void DFS(int cur)
{
    visit[cur] = true;
    Stack.push(cur);
    num[cur] = low[cur] = ++sccCnt;

    for(int next: adj[cur])
    {
        if (!num[next])
        {
            DFS(next);
            low[cur] = std::min(low[cur], low[next]);
        }
        else if (visit[next])
        {
            low[cur] = std::min(low[cur], num[next]);
        }
    }

    if (low[cur] == num[cur])
    {
        std::set<int> scc;
        while (!Stack.empty())
        {
            int top = Stack.top(); Stack.pop();
            scc.insert(top);
            visit[top] = false;
            if (cur == top) break;
        }
        ans.emplace_back(scc);
    }
}

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    int V, E, A, B;
    std::cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        std::cin >> A >> B;
        adj[A].insert(B);
    }

    for (int i = 1; i <= V; i++)if (!num[i]) DFS(i);

    sort(ans.begin(), ans.end());

    std::cout << ans.size() << "\n";
    for (auto SET : ans)
    {
        for (auto x : SET) std::cout << x << " ";
        std::cout << "-1\n";
    }

    return 0;
}