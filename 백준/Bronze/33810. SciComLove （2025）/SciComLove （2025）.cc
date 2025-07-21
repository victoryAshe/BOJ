#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S;
	cin >> S;

	string origin = "SciComLove";
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		if (S[i] != origin[i]) ans++;
	}
	cout << ans;

	return 0;
}