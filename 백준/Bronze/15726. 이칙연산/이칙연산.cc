#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long double A, B, C;
    cin >> A >> B >> C;
    long double result1 = A * B / C, result2 = A / B * C;
    if (result1 < result2) cout << (int)result2;
    else cout << (int)result1;

    return 0;
}