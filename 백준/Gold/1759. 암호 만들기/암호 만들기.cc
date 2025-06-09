#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L, C;
	cin >> L >> C;

	vector<bool> bits(C);
	for (int i = 0; i < L; i++) bits[i] = true;

	char c[15];
	for (int i = 0; i < C; i++) cin >> c[i];

	sort(c, c + C);

	string s;
	int vowelCnt, conCnt;
	do {
		s = "";
		vowelCnt = 0, conCnt = 0;
		for (int i = 0; i < C; ++i)
		{
			if (bits[i])
			{
				if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u') vowelCnt++;
				else conCnt++;
				s += c[i];
			}
		}
		if(vowelCnt>=1 && conCnt>=2) cout << s<<"\n";
	} while (prev_permutation(bits.begin(), bits.end()));

	return 0;
}