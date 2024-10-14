#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int P[MAX];
int main()
{
    int N; cin >> N;
    int result = 0;
    for (int i = 1; i <= N; i++) cin >> P[i];
    sort(P + 1, P + N+1);
    for (int i = 1; i <= N; i++)
    {
        P[i] += P[i - 1];
        result += P[i];
    }
    cout <<result;
    return 0;
}