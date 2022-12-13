#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int result = a < 0 ? (b>0 ? 2 : 3) : (b>0 ? 1 : 4);
    cout << result;
    
    return 0;
}