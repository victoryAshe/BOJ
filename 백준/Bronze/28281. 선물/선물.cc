#include <iostream>
#include <climits>
using namespace std;

int price[100001] = {0,};

int main()
{
    int N, X; cin >> N >> X;
    int result = INT_MAX;
    
    cin >> price[0];
    for(int i = 1; i<N; i++)
    {
        cin >> price[i];
        int cost = X*(price[i-1]+price[i]);
        if(cost < result) result = cost;
    }
    cout << result;
    return 0;
}