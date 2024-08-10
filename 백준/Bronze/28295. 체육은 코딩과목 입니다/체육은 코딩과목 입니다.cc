#include <iostream>
using namespace std;

char dir[4] = {'N', 'E', 'S', 'W'};
int currDir = 0;
int changeDir(int order)
{
    return currDir+order>3 ? currDir+order -4 :currDir+order;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int order;
    for(int i = 0; i<10; i++)
    {
        cin >> order;
        currDir = changeDir(order);
    }
    cout << dir[currDir];
    
    return 0;
}