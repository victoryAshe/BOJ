#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1001;
int arr[MAX];
int dp[MAX];
int N;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    int longestLen = 0;

    for (int i = 1; i <= N; i++) 
        cin >> arr[i];
    
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        longestLen = max(dp[i], longestLen);
    }

    cout << longestLen;
    return 0;
}