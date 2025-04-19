#include <iostream>
using namespace std;

int main()
{
    int L;
    cin >> L;
    cout << (L % 5 > 0 ? L / 5 + 1 : L / 5);
    return 0;
}