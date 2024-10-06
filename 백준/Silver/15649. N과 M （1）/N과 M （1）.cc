#include <iostream>
#include <string>
using namespace std;

const int MAX = 9;
int N, M;
bool visit[MAX];

void BackTracking(int cnt, string result)
{
    if (cnt == M)
    {
        cout << result << "\n";
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visit[i]) continue;
        else
        {
            visit[i] = true;
            BackTracking(cnt + 1, result + to_string(i + 1) + " ");
            visit[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    BackTracking(0, "");

    return 0;
}