#include <iostream>
using namespace std;

int biggest = 0;

int result(int num)
{
    if (num == 1) return biggest;

    if (num % 2 == 0) num /= 2;
    else
    {
        num *= 3; num += 1;
    }

    if (biggest < num) biggest = num;
    return result(num);
}


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T; cin >> T;
    int num;
    for (int i = 0; i < T; i++)
    {
        cin >> num;
        biggest = num;
        cout << result(num) << "\n";

    }

    return 0;
}