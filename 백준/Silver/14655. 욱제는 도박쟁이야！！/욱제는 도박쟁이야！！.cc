#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    int num;
    int answer = 0;
    for(int i = 0; i<N; i++)
    {
        cin >> num;
        answer += num>0? num : -num;
    }
    
    for(int i = 0; i<N; i++)
    {
        cin >> num;
        answer -= num>0 ? -num : num;
    }
    cout << answer << "\n";
    
    return 0;
}