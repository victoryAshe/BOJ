#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int K, num; cin >> K;
    stack<int> nums;
    for(int i = 0; i<K; i++)
    {
        cin >> num;
        if(num!=0) nums.push(num);
        else nums.pop();
    }

    int count = 0;
    while(!nums.empty())
    {
        count += nums.top();
        nums.pop();
    }
    cout << count;
    return 0;
}