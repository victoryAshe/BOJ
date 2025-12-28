#include <iostream>
#include <vector>

char cookie = '*';
int N;
int CalcLen(int y, int x, int dy, int dx, std::vector<std::vector<char>> &board)
{
    int len = 0;
    for (int j = 0; j < N; j++)
    {
        int nx = x + dx, ny = y + dy;
        if (nx<0 || nx>N || ny<0 || ny>N) break;
        if (board[ny][nx] != cookie) break;

        y = ny; x = nx;
        len++;
    }

    return len;
}

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> N;
    std::vector<std::vector<char>> board(N+1);
    std::pair<int, int> heart = {-1,-1};
    
    for (int i = 1; i <= N; i++)
    {
        board[i].resize(N + 1);
        for (int j = 1; j <= N; j++)
        {
            std::cin >> board[i][j];
            if (heart.first == -1 && board[i][j] == cookie)
                heart = { i,j };
        }
    }


    heart.first += 1;
    std::cout << heart.first << " " << heart.second << "\n";

    int dx[3] = { -1,1,0 };
    int dy[3] = { 0,0,1 };
    std::pair<int, int> spineEnd = heart;
    for (int i = 0; i < 3; i++)
    {
        int len = CalcLen(heart.first, heart.second, dy[i], dx[i], board);
        std::cout << len <<" ";
        if (i == 2)
        {
            spineEnd.first += len;
        }
    }
    std::cout << CalcLen(spineEnd.first, spineEnd.second - 1, 1, 0, board)<<" ";
    std::cout << CalcLen(spineEnd.first, spineEnd.second + 1, 1, 0, board)<<" ";

    return 0;
}