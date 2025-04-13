#include <iostream>
#include <string>
using namespace std;

int A, C, G, T;
int a = 0, c = 0, g = 0, t = 0;

bool isValid()
{
	return (a >= A && c >= C && g >= G && t >= T);
}

void CalcChar(char cur, bool isAdd)
{
	if (cur == 'A') a += isAdd ? 1 : -1;
	else if (cur == 'C') c += isAdd ? 1 : -1;
	else if (cur == 'G') g += isAdd ? 1 : -1;
	else if (cur == 'T') t += isAdd ? 1 : -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int ans = 0;

	int S, P;
	cin >> S >> P;

	string s;
	cin >> s;

	cin >> A >> C >> G >> T;

	string startString = s.substr(0, P);
	for (char c : startString) CalcChar(c, true);
	if (isValid()) ans++;

	for (int cur = P; cur < S; cur++)
	{
		CalcChar(s[cur - P], false);
		CalcChar(s[cur], true);
		if (isValid()) ans++;
	}

	cout << ans;

	return 0;
}