#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	set<int> arr;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.insert(num);
	}

	for (int x : arr) cout << x << " ";

	return 0;
}