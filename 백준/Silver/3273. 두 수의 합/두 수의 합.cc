#include <iostream>
#include <algorithm>
using namespace std;

int nums[100001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int answer = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n);

    int x;
    cin >> x;
    int front = 0, back = n - 1;
    while (front < back)
    {
        int sum = nums[front] + nums[back];

        if (sum == x)
        {
            answer++;
            front++; back--;
        }
        else if (sum < x) front++;
        else back--;
    }
    
    cout << answer;

    return 0;
}
