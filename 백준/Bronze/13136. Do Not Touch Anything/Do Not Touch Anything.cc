#include <iostream>
using namespace std;

int main()
{
    long long R, C, N; cin >> R >> C >> N;
    long long x = R/N, y = C/N;
    if (R % N > 0) x += 1;
    if (C % N > 0) y += 1;
    cout << x*y << "\n";

    return 0;
}