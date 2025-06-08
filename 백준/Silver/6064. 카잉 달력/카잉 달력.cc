#include <iostream>
using namespace std;

int GCD(int M, int N)
{
	return M % N ? GCD(N, M % N) : N;
}

int LCM(int M, int N)
{
	return M * N / GCD(M, N);
}

void Solution()
{
	int M, N, x, y;
	cin >> M >> N >> x >> y;
	int maxYear = LCM(M, N);
	
	bool isValid = true;
	while (x!=y)
	{
		if (x > y) y += N;
		else x += M;

		if (x > maxYear || y > maxYear)
		{
			isValid = false;
			break;
		}
	}

	if (isValid) cout << x;
	else cout << "-1";
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		Solution();
	}

	return 0;
}