#include <iostream>
using namespace std;

int main()
{
    int h, m;
    cin >> h >> m;

    if (m - 45 < 0)
    {
        m = 60 - 45 + m; h -= 1;
        if(h < 0) h = 23;
    }
    else m -= 45;

    cout << h << " " << m;

    return 0;
}