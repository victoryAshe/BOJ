#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 2510;

int N;
int dp[MAX];
char charString[MAX];
bool isPalindrome[MAX][MAX];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false); 

	cin >> charString + 1;

	for (N = 1; charString[N] != NULL; N++); N--;

	//===Make Palindrome===
	// len 1
	for (int i = 1; i <= N; i++) isPalindrome[i][i] = true;
	// len 2
	for (int i = 1; i < N; i++)
	{
		if (charString[i] == charString[i + 1]) isPalindrome[i][i + 1] = true;
	}
	// len 3~: start==end && isPalindrome[start+1][end-1]
	for (int len = 3; len <= N; len++)
	{
		for (int start = 1; start + len - 1 <= N; start++)
		{
			int end = start + len - 1;
			if (charString[start] == charString[end] && isPalindrome[start + 1][end - 1]) isPalindrome[start][end] = true;
		}
	}
	//===

	//===DP===
	for (int end = 1; end <= N; end++)
	{
		dp[end] = 2e9;
		for (int start = 1; start <= end; start++)
		{
			if (isPalindrome[start][end]) dp[end] = min(dp[end], dp[start - 1] + 1);
		}
	}
	//===

	cout << dp[N];

	return 0;
}