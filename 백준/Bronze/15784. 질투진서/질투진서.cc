#include <iostream>
#include <algorithm>
const int MAX = 1'001;

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N, a, b;
    std::cin >> N >> a >> b;
    int num;
    int targetScore = -1, highestScoreCanSee = -1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> num;
            if (i == a && j == b)
            {
                targetScore = num;
            }
            else if (i == a || j == b)
            {
                highestScoreCanSee = std::max(highestScoreCanSee, num);
            }
        }
    }
    if (highestScoreCanSee > targetScore) std::cout << "ANGRY";
    else std::cout << "HAPPY";

    return 0;
}