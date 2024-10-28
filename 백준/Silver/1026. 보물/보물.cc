#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int A[50], B[50];
    int result = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A, A + N, greater<int>());
    sort(B, B + N);
    for (int i = 0; i < N; i++) result += A[i] * B[i];
    cout << result;
    return 0;
}