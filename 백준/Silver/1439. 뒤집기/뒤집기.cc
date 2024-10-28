#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int result0 = 0, result1 = 0;
	int len = s.length();
	if (s[0] == '0') result0++;
	else result1++;
	for (int i = 1; i < len; i++)
	{
		if (s[i] != s[i - 1])
		{
			if (s[i] == '0') result0++;
			else result1++;
		}
	}
	
	cout << min(result0, result1);

	return 0;
}