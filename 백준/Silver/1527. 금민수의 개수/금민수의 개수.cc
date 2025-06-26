#include <iostream>
#include <string>
#include <stack>
using namespace std;

typedef long long ll;
ll A, B;

int DFS (string s)
{
	bool isValid = false;
	if (s.length() > 0)
	{
		ll num = stod(s);
		if (num > B) return isValid;
		if (A <= num) isValid = true;
	}

	return isValid + DFS(s + "4") + DFS(s + "7");
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	cout << DFS("");

	return 0;
}