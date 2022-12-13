#include <iostream>
using namespace std;

int main()
{
    int h, m, added;
    cin >> h >> m >> added;

    m += added % 60;
    h += added / 60;
    if (m > 59)
    {
        m -= 60; h++;
    }
    if (h > 23) h %= 24;
    cout << h << " " << m;

    return 0;
}