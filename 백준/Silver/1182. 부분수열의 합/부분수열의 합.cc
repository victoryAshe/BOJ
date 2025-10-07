#include <iostream>
using namespace std;

const int MAX = 21;

int num[MAX];
int N, S;
long long ans = 0;

void DFS(int idx, int cur)
{
    if (idx == N)
    {
        if (cur == S) ans++;
        return;
    }

    DFS(idx + 1, cur + num[idx]);
    DFS(idx + 1, cur);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> num[i];
    DFS(0, 0);
    if (S == 0) ans--;
    cout << ans;

    return 0;
}