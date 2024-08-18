#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int N; cin >> N;

    // N = 3x + 5y
    int x = 0, y = 1, result = INT_MAX;

    // N = 5y
    if (N % 5 == 0)
    {
        while (N >= 5 * y)
        {
            y++;
        }
        result = min(result, --y);
    }

    // N = 3x
    if (N % 3 == 0)
    {
        x = 1;
        while (N >= 3 * x)
        {
            x++;
        }
        result = min(result, --x);
    }

    // N = 3x+ 5y
    x = 0, y = 1;
    while (N >= 3 * x + 5 * y)
    {
        x = (N - 5 * y) / 3;
        if (5 * y + 3 * x == N)
        {
            result = min(result, x + y++);
            x = 0;
        }
        else
        {
            y++; x = 0;
        }
    }

    if (result == INT_MAX) result = -1;

    cout << result;

    return 0;
}