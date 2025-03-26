#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	string s;
	getline(cin, s);
	sort(s.begin(), s.end());

	int cnt[26] = { 0, };
	int oddCnt = 0;
	char oddAlpha;
	for (char c : s) cnt[c - 'A']++;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] % 2 == 1)
		{
			oddCnt++;
			oddAlpha = 'A' + i;
			cnt[i]--;
		}
	}
	
	if (oddCnt > 1)
	{
		cout << "I'm Sorry Hansoo";
	}
	else 
	{ 
		string ans = "", reversedAns = "";
		for (int i = 0; i < 26; i++)
		{
			while (cnt[i] > 0)
			{
				ans += ('A' + i);
				cnt[i] -= 2;
			}
		}

		reversedAns = ans;
		reverse(reversedAns.begin(), reversedAns.end());

		cout << ans;
		if (oddCnt == 1) cout << oddAlpha;
		cout << reversedAns;
	}
 
	return 0;
}