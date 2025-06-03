#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string H, N;
	cin >> H >> N;

	int cnt = 0, len = H.length();
	for (int i = 0; i < len; i++)
	{
		i = H.find(N, i);
		if (i != string::npos) cnt++;
		else break;
	}
	cout << cnt;
	return 0;
}