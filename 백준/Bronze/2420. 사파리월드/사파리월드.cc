#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long N, M;
    cin >> N >> M;

    cout << abs(N - M);

    return 0;
}