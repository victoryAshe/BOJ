#include <iostream>
using namespace std;

void Solution()
{
    int l, n; cin >> l >> n;
    int minTime = 0, maxTime = 0;
    for (int i = 0; i < n; i++)
    {
        int pos; cin >> pos;

        int near = min(pos, l - pos), far = max(pos, l - pos);
        minTime = max(minTime, near);
        maxTime = max(maxTime, far);
    }
    cout << minTime << " " << maxTime << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    for (int t = 0; t < T; t++) Solution();

    return 0;
}
