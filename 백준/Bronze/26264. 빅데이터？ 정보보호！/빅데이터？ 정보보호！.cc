#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int bigdata_cnt = 0, security_cnt = 0;
    string bigdata_str = "bigdata", security_str = "security!";
    
    int N;
    cin >> N;

    string s;
    cin >> s;
    size_t i = 0;
    while (i != string::npos)
    {
        i = s.find(bigdata_str, i);
        if (i != string::npos)
        {
            bigdata_cnt++;
            i++;
        }
    }

    security_cnt = N - bigdata_cnt;
    if (security_cnt < bigdata_cnt) cout << bigdata_str << "?";
    else if (security_cnt > bigdata_cnt) cout << security_str;
    else cout << bigdata_str << "? " << security_str;

    return 0;
}