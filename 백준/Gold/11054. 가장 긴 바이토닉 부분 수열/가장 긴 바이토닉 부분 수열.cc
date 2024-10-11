#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 1001;
int arr[MAX];
int dpL[MAX];
int dpR[MAX];
int main()
{
    int N; cin >> N;
    int longestLen = 0;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++)
    {
        dpL[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                dpL[i] = max(dpL[i], dpL[j] + 1);
            }
        }
    }
    
    for (int i = N; i >=1; i--)
    {
        dpR[i] = 1;
        for (int j = i+1; j<=N; j++)
        {
            if (arr[i] > arr[j])
            {
                dpR[i] = max(dpR[i], dpR[j] + 1);
            }
        }
        longestLen = max(longestLen, dpL[i] + dpR[i]-1);
    }
    cout << longestLen;
    return 0;
}