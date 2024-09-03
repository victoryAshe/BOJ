#include <iostream>
using namespace std;

int node[201];
int depth[201];

int plan[1001];

int find(int i)
{
    if (i == node[i]) return i;
    return node[i] = find(node[i]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return;
    if (depth[x] > depth[y]) swap(x, y);
    node[x] = y;
    if (depth[x] == depth[y]) depth[y]++;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    // Init nodes
    for (int i = 1; i <= N; i++)
    {
        node[i] = i;
        depth[i] = 1;
    }

    // Make graph
    for (int i = 1; i <= N; i++)
    {
        int num;
        for (int j = 1; j <= N; j++)
        {
            cin >> num;
            if (num == 1)
            {
                merge(i, j);
            }
        }
    }

    // Check the plan is possible
    bool isPossible = true;
    for (int i = 0; i < M; i++)
    {
        cin >> plan[i];
        if (i > 0 && find(plan[i - 1]) != find(plan[i]))
        {
            isPossible = false;
        }
    }
    if (isPossible) cout << "YES";
    else cout << "NO";
    return 0;
}