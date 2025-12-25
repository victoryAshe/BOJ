#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num[MAX+1];
    for (int i = 1; i <= MAX; i++) num[i] = i;

    int a, b;
    for (int t = 0; t < 10; t++)
    {
        cin >> a >> b;
        reverse(num + a, num + b + 1);
    }

    for (int i = 1; i <= MAX; i++) cout << num[i] <<" ";

    return 0;
}