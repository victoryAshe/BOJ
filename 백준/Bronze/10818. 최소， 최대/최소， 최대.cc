#include <iostream>
#include <climits>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    int minNum = INT_MAX, maxNum = INT_MIN;
    for(int i = 0; i<N; i++)
    {
        int num; cin >> num;
        if(num > maxNum) maxNum = num;
        if(num<minNum) minNum = num;
    }
    
    cout << minNum <<" "<<maxNum;
       
    return 0;
}