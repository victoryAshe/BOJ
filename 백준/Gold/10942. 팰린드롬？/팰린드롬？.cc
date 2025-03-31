#include <iostream>
using namespace std;

int num[2001];
bool isPalindrome[2001][2001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
		isPalindrome[i][i] = true;
	}

	for (int i = 1; i < N; i++) if (num[i] == num[i + 1]) isPalindrome[i][i + 1] = true;

	for (int len = 2; len<N; len++)
	{
		for (int i = 1; i + len <= N; i++)
		{
			int j = i + len;
			if (num[i] == num[j] && isPalindrome[i + 1][j - 1])
				isPalindrome[i][j] = true;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		cout << isPalindrome[S][E] << "\n";
	}

	return 0;
}