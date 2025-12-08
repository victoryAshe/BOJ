#include <iostream>
using namespace std;

const int CNT = 30;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num; 
    bool submitted[CNT + 1] = { false, };
    for (int i = 0; i < 28; i++)
    {
        cin >> num;
        submitted[num] = true;
    }

    for (int i = 1; i <= CNT; i++) 
        if (!submitted[i])cout << i << "\n";

        return 0;
}