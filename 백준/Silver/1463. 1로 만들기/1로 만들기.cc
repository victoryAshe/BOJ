#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000001;
int cache[MAX];

int DP(int x)
{
    if (x == 1) return 0;
    if (x < 1) return MAX;
    if (cache[x] != 0) return cache[x];
    return cache[x] = min(min( (x%3==0? DP(x/3):MAX), (x%2==0?DP(x/2):MAX)), DP(x-1))+1;
}

int main()
{
    int N; cin >> N;
    cout << DP(N);

    return 0;
}