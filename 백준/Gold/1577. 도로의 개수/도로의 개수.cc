#include <iostream>
#include <cstring>

using ll = long long;

const int MAX = 101;
int dy[2] = { 1,0 };
int dx[2] = { 0,1 };

bool map[MAX][MAX][2];
ll dp[MAX][MAX];

int N, M;
ll Solution(int y, int x)
{
    if (y == N && x == M) return 1;

    ll& cur = dp[y][x];
    if (cur != -1) return cur;

    cur = 0;
    for (int i = 0; i < 2; ++i)
    {
        if (!map[y][x][i])
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny <= N && nx <= M)
            {
                cur += Solution(ny, nx);
            }
        }
    }
    return cur;
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    dp[0][0] = 1;
    int K; std::cin >> N >> M >> K;

    while(K--)
    {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        if (a > c) std::swap(a, c);
        else if (b > d) std::swap(b, d);
        
        if (a < c) map[a][b][0] = 1;
        else if (b < d) map[a][b][1] = 1;
    }

    memset(dp, -1, sizeof(dp));

    std::cout << Solution(0, 0);

    return 0;
}