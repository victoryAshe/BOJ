#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, F;
    while(true)
    {
        cin >> M >> F;
        if(M==0 && F==0) break;
        cout << M+F<<"\n";
    }
    
    return 0;
}