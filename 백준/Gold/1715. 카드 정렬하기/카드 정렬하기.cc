#include <iostream>
#include <queue>
using namespace std;

int arr[100001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    long long answer = 0;
    priority_queue<long long> PQ;
    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        PQ.push(-num);
    }
    
    while (!PQ.empty())
    {
        long long a = -PQ.top();
        PQ.pop();
        if (PQ.empty()) break;

        long long b = -PQ.top();
        PQ.pop();
        answer += a + b;
        PQ.push( - (a + b) );
    }
    cout << answer;
    return 0;
}