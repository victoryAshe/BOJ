#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int V, E; cin >> V >> E;
		cout << E - V + 2 << '\n';
	}

	return 0;
}