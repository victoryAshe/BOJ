#include <iostream>
using namespace std;

int asc[8] = { 1,2,3,4,5,6,7,8 };
int des[8] = { 8,7,6,5,4,3,2,1 };
int arr[8];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 8; i++) cin >> arr[i];
	if (equal(arr, arr+8, asc)) cout << "ascending";
	else if (equal(arr, arr+8, des)) cout << "descending";
	else cout << "mixed";
	return 0;
}