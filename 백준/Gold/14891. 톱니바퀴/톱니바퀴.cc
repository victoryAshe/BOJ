#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int wheel[4][8];
int prevState[8] = {0,};    // 회전 시 이전 상태를 저장하는 배열

void Turn(int currWheel[], size_t size, int dir)
{
    copy_n(currWheel, 8, prevState);

    dir = -dir;
    int toothIdx;
    for (int i = 0; i < 8; i++)
    {
        toothIdx = i + dir;
        if (toothIdx < 0) toothIdx = 7;
        else if (toothIdx > 7) toothIdx = 0;
        currWheel[i] = prevState[toothIdx];
    }
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    char line[10];
    for (int i = 0; i < 4; i++)
    {
        cin.getline(line, 9);
        for (int j = 0; j < 8; j++)
            wheel[i][j] = line[j] - 48;
    }

    int K; cin >> K;
    int idx, dir;
    bool canBeRotated[4][2];
    for (int i = 0; i < K; i++)
    {
        cin >> idx >> dir;
        idx--;
        // 다른 바퀴에 영향을 받아 회전될 수 있는지 확인
        for (int j = 0; j < 4; j++)
        {
            if (j > 0)
            {
                canBeRotated[j][0] = wheel[j][6] != wheel[j - 1][2];
            }
            if (j < 3)
            {
                canBeRotated[j][1] = wheel[j][2] != wheel[j + 1][6];
            }
        }

        //지정된 톱니바퀴의 회전 수행
        Turn(wheel[idx], 8, dir);

        // 위의 조건에 따라 회전될 톱니바퀴 확인 및 회전 수행
        int left = 1, right = 1, tempDir = -dir;

        while (canBeRotated[idx][0] == true)
        {
            if (idx >= left && canBeRotated[idx - left][1] == true)
            {
                Turn(wheel[idx - left], 8, tempDir);
                left++;
                tempDir = -tempDir;
            }
            else break;
        }
        tempDir = -dir;
        while (canBeRotated[idx][1] == true)
        {
            if (idx + right <= 3 && canBeRotated[idx + right][0] == true)
            {
                Turn(wheel[idx + right], 8, tempDir);
                right++;
                tempDir = -tempDir;
            }
            else break;
        }
    }

    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (wheel[i][0] == 1) score += pow(2, i);
    }
    cout << score;

    return 0;
}