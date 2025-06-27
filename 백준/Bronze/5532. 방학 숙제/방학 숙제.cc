#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	cout << L - max(B / D + (B % D > 0), A / C + (A % C > 0));
	return 0;
}