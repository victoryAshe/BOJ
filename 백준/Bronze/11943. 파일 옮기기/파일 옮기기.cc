#include <iostream>
using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (A+D > B+C ? B+C : A+D);
    
    return 0;
}