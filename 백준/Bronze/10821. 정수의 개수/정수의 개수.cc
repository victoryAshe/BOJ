#include <iostream>
using namespace std;

int main()
{
    char s[105];
    cin.getline(s, 101);
    
    int result = 0;
    for(int i = 0; i<100; i++)
    {
        if(s[i]==',') result++;
    }
    cout << ++result;
    
    return 0;
}