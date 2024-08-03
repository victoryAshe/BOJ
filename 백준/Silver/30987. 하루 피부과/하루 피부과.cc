#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int x1, x2;
    cin >> x1 >> x2;

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    cout << (a / 3 * pow(x2, 3) + (b - d) / 2 * pow(x2, 2) + (c - e) * x2) 
        - (a / 3 * pow(x1, 3) + (b - d) / 2 * pow(x1, 2) + (c - e) * x1)<< "\n";

    return 0;
}