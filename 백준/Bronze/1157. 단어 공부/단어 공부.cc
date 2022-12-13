#include <map>
#include <iostream>
using namespace std;

int main()
{
	char result;

	//input
	string s = "";
	cin >> s;

	//calculate
	map<char, int> alpha;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (islower(s[i])) s[i] -= 32;
		if (alpha.find(s[i]) == alpha.end())
			alpha[s[i]] = 1;
		else alpha[s[i]]++;
	}

	int cnt = 0;
	map<char, int>::iterator p;
	for (p = alpha.begin(); p != alpha.end(); p++)
	{
		if (p->second > cnt)
		{
			result = p->first;
			cnt = p->second;
		}
		else if (p->second == cnt) result = '?';
	}

	cout << result;

	return 0;
}