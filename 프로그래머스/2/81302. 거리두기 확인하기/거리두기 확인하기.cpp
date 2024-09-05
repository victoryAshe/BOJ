#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isValid(vector<string>& place, int i, int j, int x, int y)
{
    if (i + y > 4 || i + y < 0 || j + x>4 || j + x < 0) return true;
    if (place[i+y][j+x] == 'X') return true;
    if (place[i+y][j+x] == 'O')
    {
        if (abs(x) + abs(y) < 2)
        {
            if (x == 0)
            {
                return isValid(place, i, j, 0, y + y)
                    && isValid(place, i, j, 1, y)
                    && isValid(place, i, j, -1, y);
            }
            else if (y == 0)
            {
                return isValid(place, i, j, x + x, 0)
                    && isValid(place, i, j, x, 1)
                    && isValid(place, i, j, x, -1);
            }
        }
        else return true;
    }
    if (place[i + y][j + x] == 'P') return false;

    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (vector<string> place : places)
    {
        bool isPlaceValid = true;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (place[i][j] == 'P')
                {
                    if( (isValid(place, i, j, 0, 1)
                        && isValid(place, i, j, 0, -1)
                        && isValid(place, i, j, 1, 0)
                        && isValid(place, i, j, -1, 0)) == false)
                        isPlaceValid = false;
                }
            }
            
        }
        answer.push_back(isPlaceValid);
    }

    return answer;
}