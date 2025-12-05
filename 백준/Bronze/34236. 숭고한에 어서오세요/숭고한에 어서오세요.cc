#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<int> year(N);
    for (int i = 0; i < N; i++) cin >> year[i];
    cout << year[N - 1] * 2 - year[N - 2];

    return 0;
}
