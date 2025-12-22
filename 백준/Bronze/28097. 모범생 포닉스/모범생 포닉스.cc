#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int T, ans = -8;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        ans += T + 8;
    }
    
    cout << ans / 24 << " " << ans % 24;

    return 0;
}