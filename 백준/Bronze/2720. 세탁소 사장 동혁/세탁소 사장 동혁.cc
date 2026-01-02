#include <iostream>

int CalculateCoin(int &C, int val)
{
    int coin = C / val;
    C %= val;
    return coin;
}

void Solution()
{
    int C; std::cin >> C;

    std::cout << CalculateCoin(C, 25) << " "
        << CalculateCoin(C, 10) << " "
        << CalculateCoin(C, 5) << " "
        << CalculateCoin(C, 1) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;
    for (int t = 0; t < T; t++)
        Solution();

    return 0;
}