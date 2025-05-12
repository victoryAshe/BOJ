#include <iostream>
using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int scoreA, scoreB;
	int aWin = 0, bWin = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> scoreA >> scoreB;
		if (scoreA > scoreB) aWin++;
		else if (scoreA < scoreB) bWin++;
	}
	cout << aWin << " " << bWin;
	return 0;
}