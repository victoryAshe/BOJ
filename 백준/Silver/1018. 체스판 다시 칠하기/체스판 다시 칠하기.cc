#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minCount = 2147483647;

int countRepaint(vector<vector<char>>& board, int startI, int startJ, bool isStartsWithBlack)
{
    int count = 0;
    for (int i = startI; i < 8 + startI; i++)
    {
        for (int j = startJ; j < 8 + startJ; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (isStartsWithBlack)
                {
                    if (board[i][j] != 'B') count++;
                }
                else if (board[i][j] != 'W') count++;
            }
            else
            {
                if (isStartsWithBlack)
                {
                    if (board[i][j] != 'W') count++;
                }
                else if (board[i][j] != 'B') count++;
            }
        }
    }
    return count;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector<vector<char>> board(N);
    char colour;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> colour;
            board[i].push_back(colour);
        }
    }

    
    N -= 8; M -= 8;
    if (N == 0 && M == 0) minCount = min(countRepaint(board, 0, 0, true), countRepaint(board, 0, 0, false));
    else
    {
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= M; j++)
            {
                minCount = min(minCount, min(countRepaint(board, i, j, true), countRepaint(board, i, j, false)));
            }
        }
    }
    
    cout << minCount;

    return 0;
}