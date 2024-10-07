#include <iostream>
using namespace std;

const int MAX = 100001;
int sum[MAX];
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for (int i = 0; i < M; i++)
    {
        int start, end; cin >> start >> end;
        cout << sum[end] - sum[start-1] << "\n";
    }
    return 0;
}