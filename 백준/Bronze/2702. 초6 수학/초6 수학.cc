#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    int result = 0;
    int maxCount = a< b? a : b;
    for(int i = 1; i<=maxCount; i++)
    {
        if(a%i==0 && b%i==0)
        {
            result = i;
        }
    }
    
    return result;
}

int LCM(int a, int b)
{
    int gcd = GCD(a, b);
    if(gcd == 1) return a*b;
    return a*(b/gcd);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    int a, b;
    for(int i = 0; i<T; i++)
    {
        cin >> a >> b;
        cout << LCM(a,b) <<" "<< GCD(a,b)<<"\n";
    }
    
    return 0;
}