#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char c; cin >> c;
	char N = 'N', n = 'n';
	if (c == N || c == n) cout << "Naver D2";
	else cout << "Naver Whale";

	return 0;
}