#include <iostream>
#include <string>
using namespace std;

int main()
{
    char result;
    int score;
    cin >> score;
    
    if(score>=90) result = 'A';
    else if(score>=80) result = 'B';
    else if(score>=70) result = 'C';
    else if(score>=60) result = 'D';
    else result = 'F';
    
    cout << result;
    
    
    return 0;
}