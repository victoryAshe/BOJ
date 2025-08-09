#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

typedef vector<vector<int>> intVec;

intVec Slice(const intVec& target)
{
	int H = min(target.size(), (size_t)100), W = min(target[0].size(), (size_t)100);
	intVec ret(H, vector<int>(W));
	for (int i = 0; i < H; i++)
	{
		ret[i].assign(target[i].begin(), target[i].begin() + W);
	}
	return ret;
}

intVec Sort(const intVec &target)
{
	int H = target.size(), W = target[0].size();
	intVec ret(H);

	size_t len = 0;

	for (int i = 0; i < H; i++)
	{
		unordered_map<int, int> countNum;
		for (int x : target[i])
		{
			if (x == 0) continue;
			if (countNum.find(x) == countNum.end())
				countNum[x] = 1;
			else countNum[x]++;
		}

		vector<pair<int, int>> countVec;
		for (auto p : countNum)
		{
			countVec.push_back(make_pair(p.second, p.first));
		}
		sort(countVec.begin(), countVec.end());
		
		for (auto p : countVec)
		{
			ret[i].push_back(p.second);
			ret[i].push_back(p.first);
		}
		
		len = max(len, ret[i].size());
	}

	for (int i = 0; i < H; i++)
	{
		if (ret[i].size() < len)
		{
			size_t diff = len - ret[i].size();
			for (int t = 0; t < diff; t++)
			{
				ret[i].push_back(0);
			}
		}
	}

	ret = Slice(ret);

	return ret;
}
intVec Reverse(const intVec& target)
{
	int H = target.size(), W = target[0].size();
	intVec ret(W, vector<int>(H));
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			ret[i][j] = target[j][i];
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int r, c, k;
	cin >> r >> c >> k;
	r -= 1; c -= 1;

	// Input
	intVec A(3, vector<int>(3));
	for(int i = 0; i<3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> A[i][j];
		}
	}

	// Solution
	int H, W;
	int ans = 0;
	while (ans <= 100)
	{
		H = A.size(), W = A[0].size();
		if (H > r && W > c && A[r][c] == k) break;

		if (H >= W) // Calc R
		{
			A = Sort(A);
		}
		else // Calc C
		{
			intVec ret =  Reverse(A);
			ret = Sort(ret);
			A = Reverse(ret);
		}

		ans++;
	}

	// Print Answer
	if (ans > 100) cout << "-1";
	else cout << ans;

	return 0;
}