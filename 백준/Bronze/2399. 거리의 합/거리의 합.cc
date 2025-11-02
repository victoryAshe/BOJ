#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;
ll x[10'001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    for (ll i = 0; i < n; i++) ans += x[i] * (2LL * i - n + 1LL);
    cout << ans*2;
    return 0;
}