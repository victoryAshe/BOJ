#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M, num; 
    map<int, int> numCounts;
    cin >> N;
    for(int i = 0; i<N; i++)
    {
        cin >> num;
        if(numCounts.find(num)==numCounts.end())
        {
            numCounts[num] = 1;
        }
        else numCounts[num]++;
    }
    
    cin >> M;
    for(int i = 0; i<M; i++)
    {
        cin >> num;
        if(numCounts.find(num)==numCounts.end())
        {
            cout << 0 << " ";
        }
        else cout << numCounts[num] << " ";
    }
     
    return 0;
}