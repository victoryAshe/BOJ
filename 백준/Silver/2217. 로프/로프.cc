#include <iostream>
#include <algorithm>
using namespace std;

int ropes[100001];
int main()
{
    int N, result = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> ropes[i];
    sort(ropes, ropes + N);
    for (int i = N - 1; i >= 0; i--)
    {
        result = max(result, ropes[i]);
        int balancedWeight = (N - i) * ropes[i];
        result = max(result, balancedWeight);
        if (balancedWeight < ropes[N - 1]) break;
    }
    cout << result;
    return 0;
}