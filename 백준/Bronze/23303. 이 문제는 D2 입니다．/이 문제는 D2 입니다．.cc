#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s, D2 = "D2", d2 = "d2";
	bool isD2 = false;
	while (!cin.eof())
	{
		cin >> s;
		if (s.find(D2) != string::npos || s.find(d2) != string::npos)
		{
			isD2 = true;
			cout << "D2";
			break;
		}
	}
	if (!isD2) cout << "unrated";
	return 0;
}