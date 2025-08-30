#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int num = (M + K - 3)%N;

	while (num < 1) num += N;

	cout<< num;

	return 0;
}