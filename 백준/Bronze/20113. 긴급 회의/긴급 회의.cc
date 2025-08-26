#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> ballot(N+1);
	int vote;
	for (int i = 0; i < N; i++)
	{
		cin >> vote;
		ballot[vote]++;
	}

	pair<int, vector<int>> imposter = {0, vector<int>()};

	for (int i = 1; i <= N; i++)
	{
		if (ballot[i] > imposter.first)
		{
			imposter = { ballot[i], {i} };
		}
		else if (ballot[i] == imposter.first)
		{
			imposter.second.emplace_back(i);
		}
	}

	if (imposter.first==0 || imposter.second.size() > 1) cout << "skipped";
	else cout << imposter.second[0];

	return 0;
}