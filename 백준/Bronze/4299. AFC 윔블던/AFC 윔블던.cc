#include <iostream>
using namespace std;

int main()
{
	int add, sub;
	cin >> add >> sub;

	int midResult = add - sub;
	if (midResult<0 || midResult%2>0)
	{
		cout << "-1";
		return 0;
	}

	int A, B;
	B = midResult / 2;
	A = add - B;

	if (B > A) swap(A, B);
	cout << A << " " << B;

	return 0;
}