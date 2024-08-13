#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    vector<int> arr;
    int num;
    for(int i = 0; i<N; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    
    sort(arr.begin(), arr.end());
    for(int x: arr) cout << x<< "\n";
    
    return 0;
}