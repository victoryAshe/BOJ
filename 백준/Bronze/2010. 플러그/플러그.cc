#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N; std::cin >> N;

    int plug, plugSum = 1-N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> plug;
        plugSum += plug;
    }

    std::cout << plugSum;

    return 0;
}