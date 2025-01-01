#include <iostream>
using namespace std;

int nums[10] = {1,1,1,1,1,1,1,1,1,1};
int setCnt = 1;
void AddSet()
{
    for(int i = 0; i<10; i++) nums[i]++;
    setCnt++;
}

int main()
{
    string s;
    cin >> s;
    
    for(char c : s)
    {
        if(nums[c-48]>0) nums[c-48]--;
        else if(c=='6' && nums[9]>0)
        {
            nums[9]--;
        }
        else if(c=='9' && nums[6]>0)
        {
            nums[6]--;
        }
        else
        {
            AddSet();
            nums[c-48]--;
        }
    }
    
    cout << setCnt;
    
    return 0;
}