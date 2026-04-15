#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int N; 
    std::cin >> N;

    std::vector<ll> nums(N);

    ll mean, mid;

    std::vector<ll> modes;
    int modeCount = 0;

    double sum = 0;

    for (int i = 0; i < N; i++)
    {
        std::cin >> nums[i];
        sum += nums[i];
    }
    
    sort(nums.begin(), nums.end());
    mid = nums[N / 2];
    
    int i = 0;
    while (i<N)
    {
        int upperIndex = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]) - nums.begin();
        int curCount = upperIndex - i;
        if (curCount > modeCount)
        {
            modeCount = curCount;
            modes = { nums[i] };
        }
        else if (curCount == modeCount)
        {
            modes.emplace_back(nums[i]);
        }
        i = upperIndex;
    }


    mean = std::round(sum / N);
    std::cout << mean << "\n" << mid <<"\n";

    if (static_cast<int>(modes.size()) == 1) std::cout << modes[0];
    else std::cout << modes[1];
     
    ll range = nums[N - 1] - nums[0];
    std::cout << "\n" << range;

    return 0;
}