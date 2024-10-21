#include <iostream>
#include <map>
#include <string>
using namespace std;

string poke[100001];

int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, int> pokeMap;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> poke[i];
		pokeMap[poke[i]] = i;
	}
	for (int i = 1; i <= M; i++)
	{
		string s; cin >> s;
		if (isdigit(s[0]))
		{
			cout << poke[stoi(s)]<<"\n";
		}
		else
		{
			cout << pokeMap[s]<<"\n";
		}
	}
	return 0;
}