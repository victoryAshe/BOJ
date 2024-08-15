#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N; cin >> N;
    int cnt10 = 0, cnt5 = 0, cnt2 = 0;
    int num;
    for (int i = 2; i <= N; i++)
    {
        num = i;
        while (num % 10 == 0)
        {
            num /= 10; cnt10++;
        }

        while (num % 5 == 0)
        {
            num /= 5; cnt5++;
        }

        while (num % 2 == 0)
        {
            num /= 2; cnt2++;
        }
 
    }
    cout << cnt10+min(cnt5, cnt2);

    return 0;
}