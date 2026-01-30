#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    while (!std::cin.eof())
    {
        char charString[110];
        std::cin.getline(charString, 110);
        std::cout << charString << "\n";
    }

    return 0;
}