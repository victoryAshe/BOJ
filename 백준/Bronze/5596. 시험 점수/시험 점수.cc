#include <iostream>
#include <cmath>
using namespace std;

int CalcSum()
{
    int score, sum = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> score; sum +=score;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << max(CalcSum(), CalcSum());
    return 0;
}
