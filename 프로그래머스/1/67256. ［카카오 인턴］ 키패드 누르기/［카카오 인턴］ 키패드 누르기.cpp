#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int locL = 10, locR = 12;
string decideHand(int x, string hand)
{
    if(x==0) x=11;
    int ld = abs(x-locL), rd = abs(x-locR);
    ld = ld / 3 + ld % 3; rd = rd / 3 + rd % 3;
    if (ld == rd)
    {
        if (hand == "right")
        {
            locR = x; return "R";
        }
        else
        {
            locL = x; return "L";
        }
    }

    if (ld > rd)
    {
        locR = x;  return "R";
    }
    else
    {
        locL = x; return "L";
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for (int x : numbers)
    {
        switch (x)
        {
        case 1: case 4: case 7:
            answer.append("L");
            locL = x;
            break;
        case 3: case 6: case 9:
            answer.append("R");
            locR = x;
            break;
        case 2: case 5: case 8: case 0:
            answer.append(decideHand(x, hand));
            break;
        }
    }
    return answer;
}