#include <iostream>
using namespace std;

int main() {

    int ans = 0, X; 
    cin >> X;

    for (int i = 6; i >= 0; i--) ans += (X >> i) & 1;

    cout << ans;
    return 0;
}