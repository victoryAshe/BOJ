#include <iostream>
using namespace std;

void Solution()
{
	string s;
	cin >> s;
	if (s.length() < 6 || s.length() > 9)
		cout << "no\n";
	else cout << "yes\n";
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		Solution();
	}

	return 0;
}