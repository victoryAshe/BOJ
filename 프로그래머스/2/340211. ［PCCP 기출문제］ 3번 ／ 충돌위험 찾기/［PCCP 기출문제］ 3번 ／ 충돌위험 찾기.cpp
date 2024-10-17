#include <vector>
#include <algorithm>
using namespace std;

vector<int> board[105][105];


void FindPath(vector<vector<int>>& points, vector<int>& route)
{
    int len = route.size();
    int x = points[route[0] - 1][0], y = points[route[0] - 1][1];
    int time = 1;

    board[x][y].push_back(time);
    for (int i = 1; i < len; i++)
    {
        int next = route[i] - 1;
        int nextX = points[next][0];
        int nextY = points[next][1];

        // row 이동
        while (x != nextX)
        {
            if (nextX > x) x++;
            if (nextX < x) x--;
            time++;
            board[x][y].push_back(time);
        }

        // column 이동
        while (y != nextY)
        {
            if (nextY > y) y++;
            if (nextY < y) y--;
            time++;
            board[x][y].push_back(time);
        }
    }
}


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    for (auto route : routes) FindPath(points, route);
    
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            sort(board[i][j].begin(), board[i][j].end());
            board[i][j].push_back(-1); // 아무것도 없는 배열일 경우, index error 방지
            int len = board[i][j].size();
            int pre = board[i][j][0];
            int cnt = 0;
            for (int k = 1; k < len; k++)
            {
                int cur = board[i][j][k];
                if (pre == cur) cnt++;
                else
                {
                    if (cnt) answer++;
                    pre = cur;
                    cnt = 0;
                }
            }
        }
    }
    return answer;
}