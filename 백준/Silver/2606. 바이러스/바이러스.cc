#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 101;
bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;

int result = 0;

void BFS(int start)
{
    visit[start] = true;
    Q.push(start);
    
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        
        int size = adj[cur].size();
        for(int i = 0; i<size; i++)
        {
            int next = adj[cur][i];
            if(!visit[next])
            {
                result++;
                visit[next] = true;
                Q.push(next);
            }
        }
    }
}

int main()
{
    int N, M; 
    cin >> N >> M;
    
    // 간선 정보 입력
    for(int i = 0; i<M; i++)
    {
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
    
    BFS(1);
    cout << result;
    
    return 0;
}