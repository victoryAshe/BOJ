#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num == 1) return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int M, N; cin >> M >> N;
    for (int num = M; num <= N; num++)
    {
        if (isPrime(num) == true) cout << num << "\n";
    }

    return 0;
}