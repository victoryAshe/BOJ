#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N; cin >> N;
    if (N < 3)
    {
        cout << N;
        return 0;
    }


    // 등비수열의 합
    int rN = 1, rSum = 2;
    while (true)
    {
        if (2 + 2 * (pow(2, rN) - 1) < N)
        {
            rSum = 2 + 2 * (pow(2, rN) - 1);
            rN++;
        }
        else break;

    }

    // 등차수열의 일반항
    cout << 2 *(N-rSum);
    

    return 0;
}