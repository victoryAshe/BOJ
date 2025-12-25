#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, num; cin >> N;
    int young_sik = 0, min_sik = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        young_sik += (num / 30 + 1) * 10;
        min_sik += (num / 60 + 1) * 15;
    }

    int less = min(young_sik, min_sik);
    if (less==young_sik) cout << "Y ";
    if (less == min_sik) cout << "M ";
    cout << less;

    return 0;
}