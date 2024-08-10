#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, K, G, P, D; cin >> N >> K;
    
    for(int i = 0; i<K; i++)
    {
        cin >> G;
        P = G*100/N;
        if(P<=4) D = 1;
        else if(P<=11) D = 2;
        else if(P<=23) D = 3;
        else if(P<=40) D = 4;
        else if(P<=60) D = 5;
        else if(P<=77) D = 6;
        else if(P<=89) D = 7;
        else if(P<=96) D = 8;
        else D = 9;
        cout << D << " ";
    }
    
    
    return 0;
}