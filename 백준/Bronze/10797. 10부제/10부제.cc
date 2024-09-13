#include <iostream>
using namespace std;

int main()
{
    int day; cin >> day;
    int num, result = 0;
    for(int i = 0; i<5; i++)
    {
        cin >> num;
        if(num==day) result++;
    }
    
    cout << result;
    
    return 0;
}