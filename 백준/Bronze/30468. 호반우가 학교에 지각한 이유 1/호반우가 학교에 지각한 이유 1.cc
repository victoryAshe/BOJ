#include <iostream>
using namespace std;

int main()
{
    int STR, DEX, INT, LUK, N;
    cin >> STR >> DEX >> INT >> LUK >> N;
    int result = N*4 - (STR+DEX+INT+LUK);
    cout <<  (result > 0 ? result : 0);
    
    return 0;
}