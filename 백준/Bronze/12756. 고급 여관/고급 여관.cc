#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int atkA, atkB, hpA, hpB;
	cin >> atkA >> hpA >> atkB >> hpB;
	while (hpA > 0 && hpB > 0)
	{
		hpA -= atkB;
		hpB -= atkA;
	}

	cout << (hpA <= 0 && hpB <= 0 ? "DRAW" : (hpA > 0 ? "PLAYER A" : "PLAYER B"));

	return 0;
}