#include <iostream>
using namespace std;

int main()
{
    cout<<fixed;
    cout.precision(1);
    double W, H; cin >> W >> H;
    cout << W*H/2;
    return 0;
}