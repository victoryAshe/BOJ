#include <iostream>
#include <bitset>
void Solution()
{
    int N;
    std::cin >> N;

    std::bitset<21>bits(N);
    int size = static_cast<int>(bits.size());
    int cnt = bits.count();
    for (int i = 0; i < size; i++)
    {
        if (bits[i] == 1)
        {
            std::cout << i << " ";
            if (--cnt == 0) break;
        }
    }
    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int T;
    std::cin >> T;
    while (T--)
    {
        Solution();
    }

    return 0;
}