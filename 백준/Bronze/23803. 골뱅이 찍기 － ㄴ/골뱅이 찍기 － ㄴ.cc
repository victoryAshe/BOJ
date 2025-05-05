#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++) cout << "@";
			cout << "\n";
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < N; k++) cout << "@";
		}
		cout << "\n";
	}

	return 0;
}