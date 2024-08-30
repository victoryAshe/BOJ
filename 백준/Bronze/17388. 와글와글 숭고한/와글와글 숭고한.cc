#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int S, K, H; cin >> S >> K >> H;
    if(S+K+H>=100)
    {
        cout << "OK";
    }
    else 
    {
        int least = min(min(S, K), H);
        if(least == S) cout << "Soongsil";
        else if(least == K) cout << "Korea";
        else if(least == H) cout << "Hanyang";
    }
    return 0;
}