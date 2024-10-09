#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    long long ended0 = 0, ended1 = 1;
    for (int i = 2; i <= N; i++)
    {
        long long temp = ended0;
        ended0 += ended1;
        ended1 = temp;
    }
    cout << ended0 + ended1;

    return 0;
}