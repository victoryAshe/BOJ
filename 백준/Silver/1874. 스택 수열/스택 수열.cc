#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    stack<int> s; string op = "";
    int num, currNum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num > currNum)
        {
            while (num > currNum)
            {
                s.push(++currNum);
                op += "+\n";
            }
            s.pop();
            op += "-\n";
        }
        else if (s.top() == num)
        {
            s.pop();
            op += "-\n";
        }
        else
        {
            op = "NO";
            break;
        }

    }
    cout << op;

    return 0;
}