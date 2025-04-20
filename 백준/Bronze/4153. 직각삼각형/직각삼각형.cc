#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int len[3];
	while (true)
	{
		cin >> len[0] >> len[1] >> len[2];
		sort(len, len + 3);
		if (len[0] == 0) break;
		if (pow(len[2], 2) == pow(len[0], 2) + pow(len[1], 2))
			cout << "right\n";
		else cout << "wrong\n";
	}

	return 0;
}