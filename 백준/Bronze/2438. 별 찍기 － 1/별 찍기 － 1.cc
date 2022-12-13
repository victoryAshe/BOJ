#include <string>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string star = "";
    for(int i = 0; i<n; i++)
    {
        star+='*';
        cout << star << endl;
    }
    
    return 0;
}