#include <iostream>
using namespace std;

int dir[8][3] = { {0,4,8}, {0,1,2}, {0,3,6}, {1,4,7}, {2,4,6}, {2,5,8}, {3,4,5},{6,7,8} };

char IsElemValid(char a, char b, char c)
{
	if (a == b && b == c)
	{
		if (a == 'X') return 'X';
		else if (a == 'O') return 'O';
	}
	return 'F';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	
	while (true)
	{
		cin >> s;
		if (s == "end") break;

		bool isValid = true;

		int x = 0, o = 0, dot = 0;
		for (int i = 0; i < 9; i++)
		{
			if (s[i] == 'X') x++; 
			else if (s[i] == 'O') o++; 
			else dot++;
		}

		if (x > o + 1 || x < o) isValid = false;

		if (isValid)
		{
			int xWin = 0, oWin = 0;
			for (int i = 0; i < 8; i++)
			{
				char curResult = IsElemValid(s[dir[i][0]], s[dir[i][1]], s[dir[i][2]]);
				if (curResult == 'X') xWin++;
				else if (curResult == 'O') oWin++;
			}

			if ((xWin > 0 && oWin > 0)
				|| (xWin > 0 && x != o + 1)
				|| (oWin > 0 && x != o)
				|| (xWin ==0 && oWin ==0 && x+o!=9)) isValid = false;
		}

		if (isValid)
			cout << "valid\n";
		else cout << "invalid\n";
	}

	return 0;
}