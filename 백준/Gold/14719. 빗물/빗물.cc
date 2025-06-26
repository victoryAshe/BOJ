#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int water = 0;

	int H, W;
	cin >> H >> W;

	vector<int> block(W);
	for (int i = 0; i < W; i++) cin >> block[i];

	vector<int> left(W);
	left[0] = block[0];
	
	for (int i = 1; i < W; i++)
	{
		left[i] = max(block[i], left[i - 1]);
	}

	vector<int> right(W);
	right[W - 1] = block[W - 1];
	for (int i = W - 2; i >= 0; i--)
	{
		right[i] = max(block[i], right[i + 1]);
	}

	for (int i = 1; i < W-1; i++)
	{
		water += min(left[i], right[i]) - block[i];
	}
	cout << water;
	return 0;
}