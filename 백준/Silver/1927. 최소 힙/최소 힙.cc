#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> Q;
	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		if (num == 0)
		{
			if (Q.empty()) cout << "0\n";
			else
			{
				cout << Q.top() << "\n";
				Q.pop();
			}
		}
		else Q.push(num);
	}

	return 0;
}