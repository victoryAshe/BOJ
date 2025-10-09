#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
const int MAX = 41;

ll arr[MAX];
int N, S;

// Doubling으로 모든 부분합 생성
vector<ll> BuildSum(int l, int r)
{
    int k = r - l;

    vector<ll> sum;
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
    vector<ll> Left = BuildSum(0, mid);
    vector <ll> Right = BuildSum(mid, N);

    sort(Left.begin(), Left.end());
    sort(Right.begin(), Right.end());

    ll ans = 0;

    int i = 0, j = (int)Right.size() - 1;
    int LEFT_SIZE = Left.size();

    while (i < LEFT_SIZE && j >= 0)
    {
        ll sum = Left[i] + Right[j];
        if (sum < S) ++i;
        else if (sum > S) --j;
        else
        {
            ll left_val = Left[i], right_val = Right[j];
            ll left_cnt = 0, right_cnt = 0;
            while (i < LEFT_SIZE && Left[i] == left_val) 
            { 
                ++left_cnt; 
                ++i; 
            }

            while (j >= 0 && Right[j] == right_val)
            {
                ++right_cnt;
                --j;
            }
            ans += left_cnt * right_cnt;
        }
    }

    if (S == 0) ans--;
    cout << ans;

    return 0;
}