#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100001;
bool visit[MAX];
int times[MAX];
queue<int> Q;

int N, K;

void Move(int start, int end)
{
    if (end>= 0 && end < MAX && !visit[end])
    {
        times[end] = times[start] + 1;
        Q.push(end);
        visit[end] = true;
    }
}

void BFS()
{
    Q.push(N);
    visit[N] = true;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        if (cur == K) break;
        Move(cur, cur * 2);
        Move(cur, cur + 1);
        Move(cur, cur - 1);
    }
}

int main()
{
    cin >> N >> K;
    BFS();
    cout << times[K];
    return 0;
}