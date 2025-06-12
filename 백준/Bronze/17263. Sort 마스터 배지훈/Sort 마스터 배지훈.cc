#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int ans = 0;
    int N; cin >> N;
    int num;
    for(int i = 0; i<N; i++) 
    {
        cin >> num;
        ans = max(ans, num);
    }
    cout << ans;
    return 0;
}