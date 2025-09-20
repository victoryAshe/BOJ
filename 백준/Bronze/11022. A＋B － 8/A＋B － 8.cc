#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, A, B; 
	cin >> T;
	
	for (int x = 1; x <= T; x++)
	{
		cin >> A >> B;
		cout << "Case #" << x << ": " << A << " + " << B << " = " << A + B << '\n';
	}

	return 0;
}