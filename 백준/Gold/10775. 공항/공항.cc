#include <iostream>
using namespace std;

int parent[100'000];

int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int G, P;
	cin >> G >> P;
	for (int i = 1; i <= G; i++) parent[i] = i;

	int ans = 0;
	int g;
	for (int i = 0; i < P; i++)
	{
		cin >> g;
		int dock = find(g);
		if (dock == 0) break;

		ans++;
		parent[dock] = find(dock - 1);
	}

	cout << ans;

	return 0;
}