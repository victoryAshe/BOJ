#include <iostream>
#include <string>
using namespace std;

int queue[10002];
int _size = 0;

string orders[6] = { "pus", "pop", "siz", "emp", "fro", "bac" };

void Push(int X)
{
    queue[_size++] = X;
}

void Pop()
{
    if (_size == 0)
    {
        cout << "-1\n";
        return;
    }

    cout << queue[0] << "\n";
    for (int i = 1; i < _size; i++)
    {
        queue[i - 1] = queue[i];
    }
    queue[_size--] = -1;
}

void Size()
{
    cout << _size << "\n";
}

void Empty()
{
    if (_size == 0) cout << "1\n";
    else cout << "0\n";
}

void Front()
{
    if (_size == 0) cout << "-1\n";
    else cout << queue[0] << "\n";
}

void Back()
{
    if (_size == 0) cout << "-1\n";
    else cout << queue[_size - 1] << "\n";
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    string s, order; char temp[13];
    for (int i = 0; i <= N; i++)
    {
        cin.getline(temp, 12);
        s = temp;
        order = s.substr(0, 3);
        if (order.compare(orders[0]) == 0)
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
            Front();
        }
        else if (order.compare(orders[5]) == 0)
        {
            Back();
        }
    }


    return 0;
}