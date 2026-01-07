#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int A, T; 
    std::cin >> A >> T;
    int P = 10 + 2 * (25 - A + T);
    std::cout<< std::max(P, 0);


    return 0;
}