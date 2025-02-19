#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
long long scores[100000];
long long sum = 0;
long long p, q, r, S;

long long bin_search(int left, int right, int target)
{
    long long K = 1e18;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        int lowerBound = lower_bound(scores, scores + N, mid) - scores;
        int upperBound = upper_bound(scores, scores + N, mid + r) - scores;
        long long lCnt = lowerBound;
        long long rCnt = N - upperBound;
        long long nSum = sum - p * rCnt + q * lCnt;
        if (nSum < S) left = mid + 1;
        else if (nSum >= S)
        {
            K = min(K, mid);
            right = mid - 1;
        }
    }
    return K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> scores[i];
        sum += scores[i];
    }

    sort(scores, scores + N);
    cin >> p >> q >> r >> S;

    long long K = sum + q * N < S ? -1 : bin_search(1, scores[N-1] + 1, S);

    cout << K;
    return 0;
}