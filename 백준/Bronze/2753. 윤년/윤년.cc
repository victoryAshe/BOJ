#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;
    
    int result = year%4==0 &&(year%100!=0 || year%400==0) ? 1 : 0;
    cout << result;
    
    return 0;
}