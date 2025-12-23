#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int X,Y,Z,U,V,W;
    cin >> X >> Y>> Z >> U >> V >> W;
    cout << (U/100*X)+(V/50*Y)+(W/20*Z);
    
    return 0;
}