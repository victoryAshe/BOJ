#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;

void Eratos(int n, std::vector<int>& primes)
{
    std::vector<bool> v(n + 1, true);
    
    int iSize = static_cast<int>(sqrt(n));
    for (int i = 2; i <= iSize; i++)
    {
        if (v[i])
        {
            for (int k = i * i; k <= n; k += i)
            {
                v[k] = false;
            }
        }
    }

    for (int i = 2; i < static_cast<int>(v.size()); i++)
        if (v[i]) primes.emplace_back(i);
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int N; std::cin >> N;

    std::vector<int> primes;
    Eratos(N, primes);

    int ans = 0;
    int left = 0, right = 0;

    int pSize = static_cast<int>(primes.size());
    int sum = 0;
    if(pSize > 0) sum = primes[0];
    
    while (left < pSize && right < pSize)
    {
        if (sum == N) ans += 1;
        if (sum <= N)
        {
            if (++right <= pSize - 1)
                sum += primes[right];
            else break;
        }
        else sum -= primes[left++];
    }
    
    std::cout << ans;

    return 0;
}