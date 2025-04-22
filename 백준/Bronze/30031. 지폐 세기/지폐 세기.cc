#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> bills =
{
	{136, 1'000}, {142, 5'000}, {148, 10'000}, {154, 50'000}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int balance = 0;
	for (int i = 0; i < N; i++)
	{
		int w, h;
		cin >> w >> h;
		balance += bills[w];
	}

	cout << balance;

	return 0;
}