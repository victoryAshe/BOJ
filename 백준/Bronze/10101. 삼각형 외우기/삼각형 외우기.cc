#include <iostream>
using namespace std;

string Solution(int a, int b, int c)
{
	if (a == 60 && a == b && b == c) return "Equilateral";
	if (a + b + c == 180)
	{
		if (a == b || b == c || a == c) return "Isosceles";
		return "Scalene";
	}
	else return "Error";

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	cout << Solution(a, b, c);

	return 0;
}