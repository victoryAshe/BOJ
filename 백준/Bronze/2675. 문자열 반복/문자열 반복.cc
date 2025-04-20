#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int R; string s;
		cin >> R >> s;
		for (char c : s)for (int r = 0; r < R; r++) cout << c;
		cout << "\n";
	}

	return 0;
}