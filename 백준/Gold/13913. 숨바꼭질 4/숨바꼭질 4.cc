#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100'001;
const int INF = 987654321;
bool visit[MAX_SIZE];
int parent[MAX_SIZE];

void CalcPQ(int &cur, int& next, int& next_time, priority_queue<pair<int, int>>& pq)
{
    if (next >= 0 && next < MAX_SIZE && !visit[next])
    {
        visit[next] = true;
        parent[next] = cur;
        pq.push({ next_time, next });
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    memset(parent, -1, sizeof(parent));

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, N });
    visit[N] = true;

    int cur, time;
    while (!pq.empty())
    {
        cur = pq.top().second;
        time = pq.top().first;
        int next_time = time - 1;
        pq.pop();

        if (cur == K) break;

        int teleport = cur * 2;
        CalcPQ(cur, teleport, next_time, pq);

        int forward = cur + 1;
        CalcPQ(cur, forward, next_time, pq);

        int back = cur - 1;
        CalcPQ(cur, back, next_time, pq);
    }

    cout << -time << '\n';

    stack<int> path;
    while (cur != -1)
    {
        path.push(cur);
        cur = parent[cur];
    }
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }

    return 0;
}