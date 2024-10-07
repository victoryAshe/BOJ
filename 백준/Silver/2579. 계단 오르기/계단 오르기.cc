#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 301;
int score[MAX];
int cache[MAX][3];

int N;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> score[i];
    
    for (int i = 1; i <= N + 1; i++)
    {
        cache[i][0] = max(cache[i - 1][1], cache[i - 1][2]);
        cache[i][1] = cache[i - 1][0] + score[i];
        cache[i][2] = cache[i - 1][1] + score[i];
    }

    cout << max(cache[N][1], cache[N][2]);

    return 0;
}