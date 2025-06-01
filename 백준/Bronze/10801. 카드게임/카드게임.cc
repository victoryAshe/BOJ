#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cardA[10], cardB[10];
	int aWin = 0, bWin = 0;
	for (int i = 0; i < 10; i++) cin >> cardA[i];
	for (int i = 0; i < 10; i++) cin >> cardB[i];
	for (int i = 0; i < 10; i++)
	{
		if (cardA[i] > cardB[i]) aWin++;
		else if (cardA[i] < cardB[i]) bWin++;
	}

	if (aWin > bWin) cout << 'A';
	else if (aWin < bWin) cout << 'B';
	else cout << 'D';

	return 0;
}