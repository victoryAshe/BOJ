#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;
    int sub = N < B ? B : N;
    if (sub > A) cout << "Bus";
    else if (sub < A) cout << "Subway";
    else cout << "Anything";

    return 0;
}