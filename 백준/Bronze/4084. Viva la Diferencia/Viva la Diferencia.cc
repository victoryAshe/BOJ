#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, d; a = b = c = d = -1;
    while (true)
    {
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        int result = 0;
        while (true)
        {
            if (a == b && b == c && c == d) break;
            int tempA = a;
            a = abs(a - b); 
            b = abs(b - c);
            c = abs(c - d);
            d = abs(d - tempA);
            result++;
        }
        cout << result << "\n";
    }
    return 0;
}