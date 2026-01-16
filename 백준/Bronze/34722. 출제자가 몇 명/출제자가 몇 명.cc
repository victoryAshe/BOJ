#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N; std::cin >> N;
    int s, c, a, r;
    
    int res = 0;
    bool isExaminer;
    for (int i = 0; i < N; i++)
    {
        std::cin >> s >> c >> a >> r;
        isExaminer =
            (s >= 1000) || (c >= 1600) || (a >= 1500) || (r > 0 && r <= 30);
        if (isExaminer) res += 1;
    }

    std::cout << res;

    return 0;
}