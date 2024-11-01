#include <iostream>
using namespace std;

long long pow(int base, int exp, int mod, long long result)
{
	if (exp == 0) return 1;
	if (exp == 1) return base % mod;

	result = pow(base, exp / 2, mod, 1) % mod;
	if (exp % 2 == 0)  return result * result % mod;
	return result * result % mod * base % mod;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int A, B, C;
	cin >> A >> B >> C;
	long long result = pow(A,B,C, 1);
	cout << result;
	return 0;
}