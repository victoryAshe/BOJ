#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000001;
int cache[MAX];

int DP(int x)
{
    if (x <=2) return x;
    if (x == 3) return 4;
    if (x < 1) return 0;
    if (cache[x] != 0) return cache[x];
    return cache[x] = DP(x-1) + DP(x-2)+DP(x-3);
}

int main()
{
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; cin >> N;
        cout << DP(N) << "\n";
    }

    return 0;
}