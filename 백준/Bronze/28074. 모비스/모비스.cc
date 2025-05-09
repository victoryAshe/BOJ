#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool alpha[26] = {false,};
	string s; cin >> s;
	for (char c : s)
	{
		alpha[c - 'A'] = true;
	}

	char mobis[5] = { 'M', 'O', 'B', 'I', 'S' };
	bool result = true;
	for (char c : mobis)
	{
		if (!alpha[c - 'A'])
		{
			result = false;
			break;
		}
	}
	cout << (result ? "YES" : "NO");

	return 0;
}