#include <iostream>
using namespace std;

char A = 'A';

void Solution()
{
    bool isBack;
    char result = A - 1;
    for(int i = 0; i<4; i++)
    {
        cin >> isBack;
        if (!isBack) result++;
    }

    if (result < A) result += 5;
    
    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int t = 0; t < 3; t++) Solution();

    return 0;
}