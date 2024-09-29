#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

stack<char> ops;

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main()
{
    char c[105];
    cin.getline(c, 101);

    int len = strlen(c);
    for (int i = 0; i < len; i++)
    {
        if (c[i] >= 'A') cout << c[i];         
        else if (c[i] == '(') ops.push(c[i]);
        else if (c[i] == ')')
        {
            while (!ops.empty())
            {
                char op = ops.top();     
                ops.pop();
                if (op == '(') break;
                else cout << op;
            }
        }
        else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
        {
            while (!ops.empty())
            {
                char op = ops.top();
                if (precedence(c[i]) <= precedence(op))
                {
                    cout << op;
                    ops.pop();
                }
                else break;
            }
            ops.push(c[i]);
        }
    }

    while (!ops.empty())
    {
        cout << ops.top();
        ops.pop();
    }

    return 0;
}