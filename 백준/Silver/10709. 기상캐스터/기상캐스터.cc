#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int H, W; cin >> H >> W;
    for(int i = 0; i<H; i++)
    {
        int latestCloud = -1;
        for(int j = 0; j<W; j++)
        {
            char c; cin >> c;
            if(c=='c') 
            {
                latestCloud = j;
                cout <<"0 ";
            }
            else if(latestCloud ==-1)
                cout << "-1 ";
            else cout << j-latestCloud<<" ";
        }
        cout <<"\n";
    }
    
    return  0;
}