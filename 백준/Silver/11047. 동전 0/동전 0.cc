#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K; 
	cin >> N >> K;
	int value[10];
	int result = 0;
	for (int i = 0; i < N; i++) cin >> value[i];

	for (int i = N - 1; i >= 0; i--)
	{
		if (value[i] > K) continue;
		result += (K-K%value[i]) / value[i];
		K %= value[i];
	}
	cout << result;
	return 0;
}