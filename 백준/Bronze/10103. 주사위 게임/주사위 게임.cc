#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int scoreA = 100, scoreB = 100;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a < b) scoreA -= b;
		else if (a > b) scoreB -= a;
	}

	cout << scoreA << '\n' << scoreB;

	return 0;
}