#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, biggest = -1;
	pair<int, int> pos;
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cin >> num;
			if (num > biggest)
			{
				biggest = num;
				pos = { i,j };
			}
		}
	}

	cout << biggest << '\n' << pos.first << " " << pos.second;

	return 0;
}