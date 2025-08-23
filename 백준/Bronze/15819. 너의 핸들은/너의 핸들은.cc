#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, I;
    cin >> N >> I;
    
    vector<string> handle(N);
    for (int i = 0; i < N; i++)
    {
        cin >> handle[i];
    }
    sort(handle.begin(), handle.end());
    
    cout << handle[I-1];

    return 0;
}