#include <iostream>
#include <map>
using namespace std;

map<char,int> scoreMap = {
    {'P', 1}, {'p', 1},
    {'N', 3}, {'n', 3},
    {'B', 3}, {'b', 3},
    {'R', 5}, {'r', 5},
    {'Q', 9}, {'q', 9}
};


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int whiteScore = 0, blackScore = 0;
    char currState; 
    
    for(int i = 0; i<64; i++)
    {
        cin >> currState;
        if(currState=='.' || currState=='K' || currState == 'k') continue;
        if(currState> 'a') blackScore+=scoreMap[currState];
        else whiteScore+=scoreMap[currState];
    }
    cout << whiteScore - blackScore;
    
    return 0;
}