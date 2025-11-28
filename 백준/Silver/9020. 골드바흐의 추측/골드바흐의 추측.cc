#include <iostream>
#include <vector>
using namespace std;

int num = 10'000;
vector<bool> prime(num + 1, true);

void Eratos()
{
    int max_bound = 10'001 / 2 + 1;
    for (int i = 2; i * i <= max_bound; i++)
    {
        if (prime[i]){
            for (int k = i * i; k <= num; k += i)
                prime[k] = false;
        }
    }
}

void Solution(int n)
{
    for (int i = n/2; i >1; i--)
    {
        if (prime[i] && prime[n-i])
        {
            cout << i << " " << n-i << "\n";
            break;
        }
    }
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
