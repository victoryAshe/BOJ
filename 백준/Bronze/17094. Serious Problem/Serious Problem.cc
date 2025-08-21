#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int len; string s;
    cin >> len >> s;
    sort(begin(s), end(s));
    int cnt_2 = s.find('e');
    int cnt_e;
    if (cnt_2 == string::npos)
    {
        cnt_e = 0;
        cnt_2 = len;
    }
    else  cnt_e = len - cnt_2;

    if (cnt_2 > cnt_e) cout << "2";
    else if (cnt_2 < cnt_e) cout << "e";
    else cout << "yee";

    return 0;
}