#include <string>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string star = "";
    for(int i = n-1; i>=0; i--)
    {
        star.append(i,' ');
        star.append(n-i, '*');
        cout << star << endl;
        star = "";
    }
    
    
    return 0;
    
}