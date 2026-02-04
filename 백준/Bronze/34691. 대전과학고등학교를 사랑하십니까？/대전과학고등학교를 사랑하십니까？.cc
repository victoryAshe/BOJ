#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> dict =
{
    {"animal", "Panthera tigris"},
    {"tree", "Pinus densiflora"},
    {"flower", "Forsythia koreana"}
};

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    std::string End = "end";
    std::string s;
    while (true)
    {
        std::cin >> s;
        if (s == End) break;
        std::cout << dict[s] << "\n";
    }

    return 0;
}