#include <iostream>
using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    int arr[1001] = { 0 };
    int result = M;
    int p = 0, dice;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int j = 1; j <= M; j++)
    {
        cin >> dice;
        p += dice;
        if (p < N) p += arr[p];
        if (p >= N)
        {
            result = j;
            break;
        }
    }
    cout << result;

    return 0;
}