#include <iostream>
using namespace std;

int narrowCount;
int normalCount;
int N;
void PrintNarrowLine()
{
    string s = "";
    for (int i = 0; i < N; i++) s += '@';
    for (int i = 0; i < narrowCount; i++) s += ' ';
    for (int i = 0; i < N; i++) s += '@';
    cout << s << "\n";
}

void PrintLine()
{
    string s = "";
    for (int i = 0; i < normalCount; i++) s += "@";
    cout << s << "\n";
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    narrowCount = N * 3;
    normalCount = N * 5;

    for (int i = 0; i < N; i++) PrintNarrowLine();
    for (int i = 0; i < N; i++) PrintNarrowLine();
    for (int i = 0; i < N; i++) PrintLine();
    for (int i = 0; i < N; i++) PrintNarrowLine();
    for (int i = 0; i < N; i++) PrintLine();

    return 0;
}