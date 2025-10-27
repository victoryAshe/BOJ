#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    int baseRM = 512;
    int A, B, C, cur;
    int minDiff = 601, ans = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> A >> B >> C;
        cur = A + B + C;
        if (cur >= baseRM)
        {
            int diff = abs(cur - baseRM);
            if (diff < minDiff)
            {
                minDiff = diff;
                ans = cur;
            }
        }
    }

    cout << ans;

    return 0;
}