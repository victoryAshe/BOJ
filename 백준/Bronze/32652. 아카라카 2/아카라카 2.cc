#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K;
	cin >> K;
	string s = "AKARAKA", add = "RAKA";
	while (--K) s+= add;

	cout << s;

	return 0;
}