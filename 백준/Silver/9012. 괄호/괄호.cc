#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    string s;
    int len;
    stack<int> opens;
    for (int i = 0; i < T; i++)
    {
        cin >> s;
        len = (int) s.length();
        opens = stack<int>();
        bool isValid = true;
        for (int j = 0; j < len; j++)
        {
            if (s[j] == '(') opens.push(j);
            else if (s[j] == ')')
            {
                if (opens.empty())
                {
                    isValid = false;
                    break;
                }
                opens.pop();
            }
        }
        if (isValid &&  opens.empty()) cout << "YES\n";
        else cout << "NO\n";


    }

    return 0;
}