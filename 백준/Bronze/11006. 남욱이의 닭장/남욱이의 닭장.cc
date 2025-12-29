#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;
    int N, M, U, V;
    for (int t = 0; t < T; t++)
    {
        std::cin >> N >> M;
        V = N - M; U = M - V;
        std::cout << U << " " << V << "\n";
    }

    return 0;
}