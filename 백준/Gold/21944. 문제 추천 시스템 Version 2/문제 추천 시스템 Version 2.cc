#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

unordered_map<int, pair<int,int>> dict;
set<pair<int,int>> problems[101]; 

void Add()
{
	int P, L, G;
	cin >> P >> L >> G;
	problems[0].insert({ L, P });	problems[G].insert({L, P});
	dict[P] = {L, G};
}

void Solved(int p) 
{
	int L = dict[p].first, G = dict[p].second;
	dict.erase(p); 
	problems[0].erase({L, p});
	problems[G].erase({L, p});
}

void Recommend(int G, int x)
{
	if (x == -1) cout << problems[G].begin()->second << "\n";
	else if (x == 1) cout << problems[G].rbegin()->second<< "\n";
}

void Recommend2(int x) { Recommend(0, x); }

void Recommend3(int x, int L)
{
	if (x == -1)
	{
		auto it = problems[0].lower_bound({ L,0 });
		if (it == problems[0].begin()) cout << "-1\n";
		else cout << prev(it)->second << "\n";
	}
	else if (x == 1)
	{
		auto it = problems[0].lower_bound({ L,0 });
		if (it != problems[0].end()) cout << it->second << "\n";
		else cout << "-1\n";
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; 
	cin >> N;
	
	for (int i = 0; i < N; i++) Add();

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string op; cin >> op;

		if (op == "add") Add();
		else if (op == "recommend")
		{
			int G, x; cin >> G >> x;
			Recommend(G, x);
		}
		else if (op == "recommend2")
		{
			int x; cin >> x;
			Recommend2(x);
		}
		else if (op == "recommend3")
		{
			int x, L; cin >> x >> L;
			Recommend3(x, L);
		}
		else if(op == "solved")
		{
			int p; cin >> p;
			Solved(p);
		}
	}

	return 0;
}