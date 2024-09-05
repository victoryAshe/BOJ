#include <iostream>
using namespace std;

int main()
{
    int out, in, people = 0, result = 0;
    
    for(int i = 0; i<10; i++)
    {
        cin >> out >> in;
        people += in - out;
        if(people > result) result = people;
    }
    cout << result;
    return 0;
}