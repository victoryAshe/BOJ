#include <iostream>
using namespace std;

int main()
{
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int MAX = N * 2 - 1;
    for (int i = MAX; i >= 1; i -= 2)
    {
        int space = (MAX - i)/2;
        for (int j = 1; j <= space; j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        cout << "\n";
    }
    for (int i = 3; i <= MAX; i += 2)
    {
        int space = (MAX - i) / 2;
        for (int j = 1; j <= space; j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        cout << "\n";
    }

    return 0;
}