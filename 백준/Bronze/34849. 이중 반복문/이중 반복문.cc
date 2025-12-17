#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int max_time = 10'000;
    int N; cin >> N;
    if (N <= max_time) cout << "Accepted";
    else cout << "Time limit exceeded";

    return 0;
}