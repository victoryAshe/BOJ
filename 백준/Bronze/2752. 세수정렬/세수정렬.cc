#include <iostream>
#include <cmath>
using namespace std;

void Comp(int& a, int& b)
{
    if (min(a, b) == b) swap(a, b);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    Comp(A, C); Comp(A, B); Comp(B, C);

    cout << A << " " << B << " " << C;
    return 0;
}