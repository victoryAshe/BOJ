#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, X, Y, R;
    cin >> N >> X >> Y >> R;

    int A = 0, B = 0;
    int T, res;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        res = abs(T - X);
        if (res == R) B++;
        else if (res < R) A++;
    }

    cout << A << " " << B;

    return 0;
}