#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int box[1001][1001];
int ripeTomato = 0;
int nullSeat = 0;
queue<pair<int, int>> Q;
int M, N;

pair<int, int> dir[4] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void Solution()
{
    int dateCount = 0;

    if (ripeTomato+nullSeat == N * M)
    {
        cout << "0";
        return;
    }
    
    while (!Q.empty())
    {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        
        for (int k = 0; k < 4; k++)
        {
            int nextI = i + dir[k].first;
            int nextJ = j + dir[k].second;
            if (nextI < 0 || nextI >= N || nextJ < 0 || nextJ >= M) continue;
            
            if (box[nextI][nextJ]==0)
            {
                box[nextI][nextJ] = box[i][j] + 1;
                dateCount = max(dateCount, box[nextI][nextJ]);
                Q.push({ nextI, nextJ });
                ripeTomato++;
            }
        }
    }

    if (ripeTomato+nullSeat == N * M) cout << dateCount-1;
    else cout << "-1";
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
            {
                Q.push({ i,j });
                ripeTomato++;
            }
            else if (box[i][j] == -1) nullSeat++;
        }
    }

    Solution();

    return 0;
}