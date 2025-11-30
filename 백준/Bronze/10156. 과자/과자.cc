#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int K, N, M;
    cin >> K >> N >> M;

    cout << max(0, K * N - M);

    return 0;
}
