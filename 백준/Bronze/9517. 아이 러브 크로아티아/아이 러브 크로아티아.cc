#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int K, N;
    cin >> K >> N;

    int timeLimit = 210;
    int curBomb = K;

    int T; char Z;
    for (int i = 0; i < N; i++)
    {
        cin >> T >> Z;
        timeLimit -= T;
        if (timeLimit <= 0) break;

        if (Z == 'T')
        {
            curBomb++;
            if (curBomb > 8) curBomb = 1;
        }
    }

    cout << curBomb;

    return 0;
}