#include <iostream>
using namespace std;

int main()
{
    int biggest = 0;
    int idx = 0;
    int num;
    for(int i = 1; i<=9; i++)
    {
        cin >> num;
        if(biggest <num) 
        {
            biggest = num; 
            idx = i;
        }
    }
    cout << biggest << "\n" <<idx;
    return 0;
}