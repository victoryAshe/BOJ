#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10001;
int arr[MAX];
int dp[MAX];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, biggestSum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= N; i++)
    {
        dp[i] = arr[i];
        for (int j = 1; j <i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j]+arr[i]);
            }
        }
        biggestSum = max(biggestSum, dp[i]);
    }
    cout << biggestSum;
    return 0;
}