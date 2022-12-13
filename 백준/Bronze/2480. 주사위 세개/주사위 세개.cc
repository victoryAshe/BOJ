#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end(), less<int>());
    
    int result;
    if(nums[0]==nums[1] && nums[1]==nums[2])
        result = 10000 + nums[0] *1000;
    else if(nums[0]==nums[1])
        result = 1000+nums[0]*100;
    else if(nums[1]==nums[2])
        result = 1000+nums[1]*100;
    else
        result = nums[2]*100;
 
    cout << result;
    
    return 0;
}