#include <iostream>
#include <cstring>
using namespace std;

bool S[21];
bool Check(int x) { return S[x]; }

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int M; cin >> M;
    string order; int x;
    for (int i = 0; i < M; i++)
    {
        cin >> order; 
        if (order == "add")
        {
            cin >> x;
            S[x] = true;
        }
        else if (order == "remove")
        {
            cin >> x;
            S[x] = false;
        }
        else if (order == "check")
        {
            cin >> x;
            if (Check(x)) cout << "1\n";
            else cout << "0\n";
        }
        else if (order == "toggle")
        {
            cin >> x;
            S[x] = !Check(x);
        }
        else if (order == "all")
            memset(S, true, sizeof(S));
        else if (order == "empty")
            memset(S, false, sizeof(S));
    }
    return 0;
}