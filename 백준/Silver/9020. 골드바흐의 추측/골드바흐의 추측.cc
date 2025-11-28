#include <iostream>
#include <vector>
using namespace std;

int num = 10'000;
vector<bool> prime(num + 1, true);

void Eratos()
{
    for (int i = 2; i * i <= num; i++)
    {
        if (prime[i]){
            for (int k = i * i; k <= num; k += i)
                prime[k] = false;
        }
    }
}

void Solution(int n)
{
    int max_bound = n/2;
    pair<int, int> ans;
    for (int i = 2; i <= max_bound; i++)
    {
        if (prime[i] && prime[n-i])
        {
            ans = { i, n - i };
        }
    }
    cout << ans.first << " " << ans.second << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Eratos();

    int T; cin >> T;
    int n;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        Solution(n);
    }

    return 0;
}
