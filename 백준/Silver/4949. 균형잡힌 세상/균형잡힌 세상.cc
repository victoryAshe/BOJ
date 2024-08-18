#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string s = "";

    stack<int> small, big;
    int smallP, bigP;

    while (s != ".")
    {
        s.clear();
        char temp[102];
        small =  stack<int>();
        big = stack<int>();
        bool isBalanced = true;
        cin.getline(temp, 101);
        s = temp;
        if (s == ".") break;
       
        int length = s.length();
        for (int i = 0; i < length; i++)
        {

            if (s[i] == '(') small.push(i);
            else if (s[i] == ')')
            {
                if (small.empty() || !big.empty() && big.top() > small.top())
                {
                    isBalanced = false; break;
                }
                small.pop();
            }
            else if (s[i] == '[') big.push(i);
            else if (s[i] == ']')
            {
                if (big.empty() || !small.empty() && small.top() > big.top())
                {
                    isBalanced = false; break;
                }
                big.pop();
            }
        }

        if (isBalanced && small.empty() && big.empty())
        {
            cout << "yes\n";
        }
        else cout << "no\n";

    }


    return 0;
}