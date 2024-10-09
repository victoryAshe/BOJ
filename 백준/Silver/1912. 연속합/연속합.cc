#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 100001;
int nums[MAX];
int dp[MAX];
int biggest = -100000000;
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        dp[i] = max(nums[i] + dp[i - 1], nums[i]);
        if (dp[i] > biggest) biggest = dp[i];
    }
    cout << biggest;
    return 0;
}