#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    cout << setprecision(20);
    long double M = (long double)(B - A) / 400;
    long double result = (long double)1 / (1 + pow(10, M));
    cout << result;
    return 0;
}