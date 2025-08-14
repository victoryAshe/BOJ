#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string doro = "DORO ";
    string ans = "", temp;
    for(int i = 0; i< N; i++)
    {
        cin >> temp;
        ans += temp + doro;
    }
    
    cout << ans;
    
    return 0;
}