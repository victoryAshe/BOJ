#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num[10] = { 0, };
    int X, Y; cin >> X >> Y;
    int max_cnt = max(X, Y);
    for (int i = 0; i < max_cnt; i++)
    {
        if (X-- > 0) num[i]++;
        if (Y-- > 0) num[i]++;
    }

    for (int i = max_cnt - 1; i >= 0; i--) cout << num[i];

    return 0;
}