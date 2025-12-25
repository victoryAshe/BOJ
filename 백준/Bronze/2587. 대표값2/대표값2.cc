#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int ave = 0, arr[MAX];
    for (int i = 0.; i < MAX; i++)
    {
        cin >> arr[i];
        ave += arr[i];
    }

    sort(arr, arr + MAX);
    ave /= MAX;

    cout << ave << "\n" << arr[MAX / 2];

    return 0;
}