#include <iostream>
using namespace std;

int Calc(int &T, int div)
{
	int result = T / div; T %= div;
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;

	int A = 300, B = 60, C = 10;
	int cntA = Calc(T,A), cntB = Calc(T,B), cntC = Calc(T,C);

	if (T > 0) cout << "-1";
	else cout << cntA << " " << cntB << " " << cntC;
	
	return 0;
}