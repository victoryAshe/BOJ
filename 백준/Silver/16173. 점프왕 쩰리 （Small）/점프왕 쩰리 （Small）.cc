#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 9;
bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;

void BFS(int start)
{
    memset(visit, false, sizeof(visit));
    visit[start] = true;
    Q.push(start);

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        int size = adj[x].size();
        for (int i = 0; i < size; i++)
        {
            int next = adj[x][i];
            if (!visit[next])
            {
                visit[next] = true;
                Q.push(next);
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num; cin >> num;
            int idx = i * N + j;
            // 오른쪽 이동
            if (j + num < N) adj[idx].push_back(idx+ num);
            // 아래쪽 이동
            if (idx + num * N < N*N)  adj[idx].push_back(idx + num * N);
        }
    }

    BFS(0);

    if (visit[N * N - 1] == true) cout << "HaruHaru";
    else cout << "Hing";

    return  0;
}