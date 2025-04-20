#include <iostream>
using namespace std;

int _gcd;

void GCD(int a, int b)
{
    int result = 0;
    int maxCount = a < b ? a : b;
    for (int i = 1; i <= maxCount; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            result = i;
        }
    }
   _gcd = result;
}

int LCM(int a, int b)
{
    if (_gcd == 1) return a * b;
    return a * (b / _gcd);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    GCD(a, b);
    cout << _gcd << "\n" << LCM(a, b) << "\n";

    return 0;
}