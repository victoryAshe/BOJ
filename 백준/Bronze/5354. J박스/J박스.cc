#include <iostream>
using namespace std;

void PrintLine(int &n)
{
	for (int i = 0; i < n; i++) cout << '#';
	cout << '\n';
}

void PrintJ(int &n)
{
	cout << '#';
	for (int i = 0; i < n - 2; i++) cout << 'J';
	cout << "#\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n; cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> n;
		PrintLine(n);
		for (int i = 0; i < n-2; i++) PrintJ(n);
		if(n-2>=0)PrintLine(n);
		cout << '\n';
	}

	return 0;
}