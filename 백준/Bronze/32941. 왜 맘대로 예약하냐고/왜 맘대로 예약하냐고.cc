#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T, X, N;
    cin >> T >> X >> N;
    bool ans = true;
    for (int n = 0; n < N; n++)
    {
        int K; cin >> K;
        bool curAttend = false;
        int num;
        for (int i = 0; i < K; i++)
        {
            cin >> num;
            if (num == X) curAttend = true;
        }
        if (!curAttend)
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO");

    return 0;
}