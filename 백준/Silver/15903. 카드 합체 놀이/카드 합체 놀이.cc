#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long> cards;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		long long n;
		cin >> n;
		cards.push(-n);
	}

	for (int i = 0; i < m; i++)
	{
		long long add = 0;
		for (int j = 0; j < 2; j++)
		{
			add -= cards.top();
			cards.pop();
		}
		for (int j = 0; j < 2; j++)
		{
			cards.push(-add);
		}
	}
	
	long long score = 0;
	while (!cards.empty())
	{
		score -= cards.top();
		cards.pop();
	}
	cout << score;

	return 0;
}