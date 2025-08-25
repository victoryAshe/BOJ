#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S;
	cin >> S;
	for (int i = 0; i < 26; i++)
	{
		int pos = S.find(i + 'a');
		cout << (pos==string::npos? "-1" : to_string(pos)) << " ";
	}

	return 0;
}