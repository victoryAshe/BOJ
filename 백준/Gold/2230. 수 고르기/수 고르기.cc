#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 2'000'000'001;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::vector<int> arr(N);
    
    for (int i = 0; i < N; i++) std::cin >> arr[i];
    sort(arr.begin(), arr.end());

    int leastDiff = INF;

    int left =0, right = 0;
    while (left < N && right < N)
    {
        int curDiff = arr[right] - arr[left];
        if (curDiff >= M)
        {
            leastDiff = std::min(leastDiff, curDiff);
            left++;
        }
        else
        {
            right++;
        }
    }

    std::cout << leastDiff;

    return 0;
}