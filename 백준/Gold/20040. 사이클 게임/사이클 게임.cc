#include <iostream>
using namespace std;

const int MAX = 500001;
int parent[MAX];
int depth[MAX];

int find(int i)
{
	if (i == parent[i]) return i;
	return parent[i] = find(parent[i]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y) return;
	if (depth[x] > depth[y]) swap(x, y);
	parent[x] = y;
	if (depth[x] == depth[y]) depth[y]++;
}

bool isCycle(int first, int second)
{
	first = find(first);
	second = find(second);
	if (first == second) return true;
	merge(first, second);
	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int result = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
		depth[i] = 1;
	}

	for (int i = 1; i <= m; i++)
	{
		int first, second;
		cin >> first >> second;
		if (isCycle(first, second))
		{
			result = i;
            break;
		}
	}

	cout << result;

	return 0;
}