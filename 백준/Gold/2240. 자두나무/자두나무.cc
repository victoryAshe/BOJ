#include <iostream>
#include <cmath>
using namespace std;
int fall[1001];
int dp[31][2][1001]; // 이동 횟수, 자두 위치, 흐른 시간

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T, W; cin >> T >> W;
    int result = 0;

    int point = 1;
    for (int i = 1; i <= T; i++) 
        cin >> fall[i];

    for (int j = 0; j <= W; j++)
    {
        for (int i = 1; i <= T; i++)
        {
            bool isFirst = fall[i] == 1;
            if(j==0)
            {
                // 처음 시작으로부터 이동하지 않은 상태(1)
                dp[j][0][i] = dp[j][0][i - 1] + isFirst;
            }
            else
            {
                // 위치의 움직임/안움직임, 받음/못받음 확인하며 체크
                /*
                * dp[이동횟수][자두의 위치][흐른 시간] = 
				*   (이동하지않고 시간만 1초 흐름 + 떨어진 위치==현재 위치), 
				*   (이동했고, 1초 흐름 + 떨어진 위치==현재 위치) 중 큰 값
                */
                dp[j][0][i] = max(dp[j][0][i - 1] + isFirst, dp[j - 1][1][i - 1] + isFirst);
                dp[j][1][i] = max(dp[j][1][i - 1] + !isFirst, dp[j - 1][0][i - 1] + !isFirst);
                result = max(result, max(dp[j][0][i], dp[j][1][i]));
            }
        }
    }

    cout << result;
    return 0;
}