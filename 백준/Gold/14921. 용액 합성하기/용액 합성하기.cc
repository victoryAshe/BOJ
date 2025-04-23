#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int pro[100'001];
int result = 200'000'001;

void MakeResult(int left, int right)
{
    while (left < right)
    {
        auto target = lower_bound(pro + left + 1, pro + right, -pro[left]);
        int curResult1 = pro[left] + *target;
        int curResult2 = pro[left] + *(target - 1);
        int curResult, idx;
        if (abs(curResult1) < abs(curResult2) || left == target - pro - 1)
        {
            curResult = curResult1;
            idx = target - pro;
        }
        else
        {
            curResult = curResult2;
            idx = target - pro - 1;
        }

        if (abs(curResult) < abs(result))
        {
            result = curResult;
            right = idx;
        }
        left++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> pro[i];
    MakeResult(0, N-1);
    cout << result;
    return 0;
}