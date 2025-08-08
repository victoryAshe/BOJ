#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<bool>> boolVec;

boolVec figure[11] = {
	{
		{0,0,0,1},
		{1,1,1,1},
		{0,0,1,0}
	},
	{
		{0,0,0,1},
		{1,1,1,1},
		{0,1,0,0}
	},
	{
		{0,0,0,1},
		{1,1,1,1},
		{1,0,0,0}
	},
	{
		{0,0,1,0},
		{1,1,1,1},
		{0,0,1,0}
	},
	{
		{0,0,1,0},
		{1,1,1,1},
		{0,1,0,0}
	},
	{
		{0,0,1,1},
		{1,1,1,0},
		{0,1,0,0}
	},
	{
		{0,0,1,1,1},
		{1,1,1,0,0}
	},
	{
		{0,0,1,1},
		{1,1,1,0},
		{0,0,1,0}
	},
	{
		{0,0,1,1},
		{1,1,1,0},
		{1,0,0,0}
	},
	{
		{0,0,1,1},
		{0,1,1,0},
		{1,1,0,0}
	},
	{
		{0,0,0,1},
		{1,1,1,1},
		{0,0,0,1}
	}
};

boolVec Normalize(const boolVec& mat)
{
	int H = mat.size(), W = mat[0].size();
	int startI = H, startJ = W;
	int endI = 0, endJ = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (mat[i][j])
			{
				startI = min(startI, i);
				startJ = min(startJ, j);
				endI = max(endI, i);
				endJ = max(endJ, j);
			}
		}
	}

	boolVec ret(endI - startI + 1, vector<bool>(endJ - startJ + 1));
	for (int i = startI; i <= endI; i++)
	{
		for (int j = startJ; j <= endJ; j++)
		{
			ret[i - startI][j - startJ] = mat[i][j];
		}
	}

	return ret;
}


boolVec Rotate90(const boolVec& mat)
{
	int H = mat.size(), W = mat[0].size();
	boolVec ret(W, vector <bool>(H));

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			ret[j][H - i - 1] = mat[i][j];
		}
	}

	ret = Normalize(ret);
	return ret;
}

boolVec Mirror(const boolVec& mat)
{
	int H = mat.size(), W = mat[0].size();
	boolVec ret(H, vector<bool>(W));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			ret[i][W - 1 - j] = mat[i][j];
		}
	}

	ret = Normalize(ret);
	return ret;
}

bool CompareFigure(const boolVec& curFigure, boolVec& target)
{
	bool result = false;
	for (int t = 0; t < 4; t++)
	{
		if (curFigure == target)
		{
			result = true;
			break;
		}
		target = Rotate90(target);
	}
	return result;
}

void Solution()
{
	bool result = false;

	boolVec input(6, vector<bool>(6));
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			bool cur;
			cin >> cur;
			input[i][j] = cur;
		}
	}

	boolVec curFigure = Normalize(input);

	for (int t = 0; t < 4; t++)
	{
		for (auto x : figure)
		{
			result = CompareFigure(curFigure, x);
			if (result) break;
			x = Mirror(x);
			result = CompareFigure(curFigure, x);
			if (result) break;
		}
		if (result) break;
		curFigure = Rotate90(curFigure);
	}

	cout << (result ? "yes" : "no") << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int t = 0; t < 3; t++)
	{
		Solution();
	}

	return 0;
}