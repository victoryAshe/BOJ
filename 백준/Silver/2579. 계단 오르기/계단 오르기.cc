#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 301;
int cache[MAX][3];

int N;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int score;
        cin >> score;
        cache[i][0] = max(cache[i - 1][1], cache[i - 1][2]);
        cache[i][1] = cache[i - 1][0] + score;
        cache[i][2] = cache[i - 1][1] + score;
    }

    cout << max(cache[N][1], cache[N][2]);

    return 0;
}