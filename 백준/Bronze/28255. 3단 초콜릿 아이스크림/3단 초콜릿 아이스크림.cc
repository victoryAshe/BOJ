#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int Solution()
{
	string s; cin >> s;

	string prefix = s.substr(0, ceil((float)s.length() / 3));
	string rev = prefix; reverse(rev.begin(), rev.end());
	string tail = prefix.substr(1);
	string rev_tail = rev.substr(1);

	string pre_rev = prefix + rev;
	string pre_revtail = prefix + rev_tail;
	
	return (s == pre_rev + prefix || s == pre_rev + tail
		|| s == pre_revtail + prefix || s == pre_revtail + tail);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	for (int t = 0; t < T; t++) cout << Solution() <<'\n';

	return 0;
}