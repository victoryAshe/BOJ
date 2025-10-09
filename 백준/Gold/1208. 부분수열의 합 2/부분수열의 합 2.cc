#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
const int MAX = 41;

int arr[MAX];
int N, S;

// Doubling으로 모든 부분합 생성
vector<int> BuildSum(int l, int r)
{
    int k = r - l;

    vector<int> sum;
    sum.reserve(1 << k);
    sum.push_back(0); // 공집합

    for (int i = l; i < r; i++)
    {
        int origin_size = (int)sum.size();
        
        // 현재 리스트를 복제하면서 +a[i]한 원소들을 뒤에 붙임
        for (int t = 0; t < origin_size; t++)
        {
            sum.push_back(sum[t] + arr[i]);
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S; 
    for (int i = 0; i < N; i++) cin >> arr[i];

    int mid = N / 2;
    vector<int> Left = BuildSum(0, mid);
    vector<int> Right = BuildSum(mid, N);

    sort(Right.begin(), Right.end());

    ll ans = 0;
    for (int x : Left)
    {
        int target = S - x;
        ll cnt = upper_bound(Right.begin(), Right.end(), target) - lower_bound(Right.begin(), Right.end(), target);
        ans += cnt;
    }

    if (S == 0) ans--;
    cout << ans;

    return 0;
}