#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long N, M, S; cin >> N >> M >> S;
	long long dis1 = S * (M + 1) * (100 - N) / 100, dis2 = S * M;
	cout << min(dis1, dis2);

	return 0;
}