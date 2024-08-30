#include <iostream>
using namespace std;

int Wn[301] = {0};

int GetWn(int n)
{
    if (n == 1) return 3;
    if (Wn[n] > 0) return Wn[n];
    else return Wn[n] = GetWn(n - 1) + (n*n*n + 3 * n*n + 2*n) / 2;
}

int main()
{
    int n; cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cout << GetWn(num) << "\n";
    }

    return 0;
}