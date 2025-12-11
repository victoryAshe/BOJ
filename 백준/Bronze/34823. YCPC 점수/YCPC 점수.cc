#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    float y, c, p;
    cin >> y >> c >> p;

    cout << min((floor(c / 2)), min(y, p));

    return 0;
}