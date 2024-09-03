#include <iostream>
using namespace std;

int node[10001];
int depth[10001];
int price[10001];

bool isFriend[10001] = { false, };

int find(int i)
{
    if (node[i] == i) return i;
    return node[i] = find(node[i]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (price[x] > price[y]) price[x] = price[y];
    else price[y] = price[x];

    if (depth[x] > depth[y]) swap(x, y);
    node[x] = y;
    if (depth[x] == depth[y]) depth[y] ++;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, k; cin >> N >> M >> k;
    for (int i = 0; i < N; i++)
    {
        node[i] = i; depth[i] = 1;
    }
    for (int i = 0; i < N; i++) cin >> price[i];
    for (int i = 0; i < M; i++)
    {
        int v, w; cin >> v >> w;
        merge(v - 1, w - 1);
    }

    int cost = 0;
    for (int i = 0; i < N; i++)
    {
        if (isFriend[find(i)] == false)
        {
            cost += price[find(i)];
            isFriend[find(i)] = true;
            isFriend[i] = true;
        }
        else
        {
            isFriend[i] = true;
        }
    }

    if (k < cost) cout << "Oh no";
    else cout << cost;

    return 0;
}