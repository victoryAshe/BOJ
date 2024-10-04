#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1000001;
int A, K;

int cnt[MAX];
queue<int> Q;

void BFS()
{
    Q.push(A);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        if (cur * 2 <= K && cnt[cur*2]==-1)
        {
            cnt[cur * 2] = cnt[cur] + 1;
            Q.push(cur * 2);
        }
        if (cur + 1 <= K && cnt[cur + 1] == -1)
        {
            cnt[cur + 1] = cnt[cur] + 1;
            Q.push(cur + 1);
        }
    }
}

int main()
{
    cin >> A >> K;

    memset(cnt, -1, sizeof(cnt));
    cnt[A] = 0;
    BFS();
    cout << cnt[K];

    return 0;
}