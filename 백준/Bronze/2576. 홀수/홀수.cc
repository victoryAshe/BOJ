#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 101;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int input, minOdd = MAX, sum = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> input;
        if (input % 2 == 1)
        {
            sum += input;
            minOdd = min(minOdd, input);
        }
    }

    if (minOdd == MAX) cout << "-1";
    else cout << sum << "\n" << minOdd;

    return 0;
}