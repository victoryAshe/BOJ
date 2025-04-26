#include <iostream>
#include <cmath>
using namespace std;

int pro[100'001];
int result = 200'000'001;

void MakeResult(int left, int right)
{
    while (left < right)
    {
        int curResult = pro[left] + pro[right];
        if (abs(curResult) < abs(result))
        {
            result = curResult;
        }
        if (curResult < 0) left++;
        else if (curResult > 0) right--;
        else break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> pro[i];
    MakeResult(0, N - 1);
    cout << result;
    return 0;
}