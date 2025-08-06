#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	if (next_permutation(num.begin(), num.end()))
	{
		for (int x : num) cout << x << " ";
	}
	else cout << "-1";

	return 0;
}