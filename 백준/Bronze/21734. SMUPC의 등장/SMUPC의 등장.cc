#include <iostream>
#include <string>
using namespace std;

void Solution(char &c)
{
	int asciiNum = c, sum = 0;
	while (asciiNum > 0)
	{
		sum += asciiNum % 10;
		asciiNum /= 10;
	}
	while (sum--) cout << c;
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	for (char c : s) Solution(c);
	
	return 0;
}