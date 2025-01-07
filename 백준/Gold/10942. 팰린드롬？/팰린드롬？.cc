#include <iostream>
using namespace std;

const int MAX = 2001;
int nums[MAX];
bool isPalindrome[MAX][MAX];

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N; 
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
		isPalindrome[i][i] = true;
		if (nums[i - 1] == nums[i]) isPalindrome[i - 1][i] = 1;
	}

	for (int gap = 2; gap < N; gap++)
	{
		for (int i = 1; i <= N - gap; i++)
		{
			int j = i + gap;
			if (nums[i] == nums[j] && isPalindrome[i + 1][j - 1]) isPalindrome[i][j] = true;
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << isPalindrome[s][e]<<"\n";
	}

	return 0;
}