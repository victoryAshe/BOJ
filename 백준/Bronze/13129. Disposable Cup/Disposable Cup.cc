#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll A, B, N;
vector<ll> ans;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> A >> B >> N;
    ans.reserve(N);

    ll cur = A * N;
    while (N--)
    {
        cur += B;
        ans.emplace_back(cur);
    }

    for (ll x : ans) cout << x << " ";

    return 0;
}