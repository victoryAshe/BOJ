#include <iostream>
using namespace std;

int main()
{
    int nums[6];
    cin >>nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4] >> nums[5];
    
    int origin[6] = {1,1,2,2,2,8};
    int result[6];
    for(int i = 0; i<6; i++)
    {
        result[i] = origin[i] - nums[i];
        cout << result[i] <<" ";
    }
    
    return 0;
}