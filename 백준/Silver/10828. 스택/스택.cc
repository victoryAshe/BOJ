#include <iostream>
#include <string>
using namespace std;

int stack[10002];
int stackPoint = -1;

string orders[5] = { "pus", "pop", "siz", "emp" , "top" };

void Push(int X)
{
    stack[++stackPoint] = X;
}

void Pop()
{
    if (stackPoint == -1)
    {
        cout << -1 << "\n";
        return;
    }

    cout << stack[stackPoint] << "\n";
    stack[stackPoint--] = -1;
}

void Size()
{
    cout << stackPoint + 1 <<"\n";
}

void Empty()
{ 
    if (stackPoint == -1) cout << 1 << "\n";
    else cout << 0 << "\n";
}

void Top()
{
    if (stackPoint == -1) cout << -1 << "\n";
    else cout << stack[stackPoint] << "\n";
}



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    string s; char temp[13];
    string order;
    for (int i = 0; i <= N; i++)
    {
        cin.getline(temp, 12);
        s = temp;

        order = s.substr(0, 3);
        if (order.compare(orders[0])==0)
        {
            Push(stoi(s.substr(5)));
        }
        else if (order.compare(orders[1]) == 0)
        {
            Pop();
        }
        else if (order.compare(orders[2]) == 0)
        {
            Size();
        }
        else if (order.compare(orders[3]) == 0)
        {
            Empty();
        }
        else if (order.compare(orders[4]) == 0)
        {
            Top();
        }
    }

    return 0;
}