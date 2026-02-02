#include <iostream>
#include <sstream>

const int MOD = 10'007;
const int MAX = 1'001;

int N, M, H;
int block[50][10];
int height[50][MAX];

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> N >> M >> H;
    std::cin.ignore();

    char cString[260];
    for (int i = 0; i < N; i++)
    {
        std::cin.getline(cString, 260, '\n');
        std::istringstream iss(cString);
        int num;
        int j = 0;
        while (iss >> num)
        {
            block[i][j++] = num;
        }
    }

    height[0][0] = 1;
    for (int j = 0; j < M; j++)
    {
        height[0][block[0][j]] = 1;
    }

    for (int i = 1; i<N; i++)
    {
        for (int j = 0; j <= H; j++)
        {
            height[i][j] = height[i - 1][j];
        }

        
        for(int j = 0; j<M; j++)
        {
            if (block[i][j] == 0) continue;
            int curHeight = block[i][j];
            for (int ix = curHeight; ix <= H; ix++)
            {
                height[i][ix] = (height[i][ix] + height[i - 1][ix - curHeight]) % MOD;
            }
        }
    }

    std::cout << height[N-1][H];

    return 0;
}