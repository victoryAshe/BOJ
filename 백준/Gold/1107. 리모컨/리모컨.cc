#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool IsValid(int N, bool(&broken)[10])
{
	string s = to_string(N);
	for (int i = 0; i < s.length(); i++)
	{
		int num = s[i] - '0';
		if (broken[num]) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool broken[10] = { false, };
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		broken[num] = true;
	}

	int cnt = abs(100 - N);
	for (int i = 0; i < 1'000'001; i++)
	{
		if (IsValid(i, broken))
		{
			int curCnt = to_string(i).length() + abs(i - N);
			cnt = min(cnt, curCnt);
		}
	}
	
	cout << cnt;

	return 0;
}