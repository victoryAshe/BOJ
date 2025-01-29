#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

struct Problem {
	int P, L, G;
	bool operator<(const Problem& other) const
	{
		if (L != other.L) return L < other.L;
		return P < other.P;
	}
};

unordered_map<int, Problem> dict;
set<Problem> problems[101]; 

void Add()
{
	int P, L, G;
	cin >> P >> L >> G;
	Problem p = { P,L,G };
	problems[0].insert(p);	problems[G].insert(p);
	dict[P] = p;
}

void Solved(int p) 
{
	Problem target = dict[p] ;
	dict.erase(p); 
	problems[0].erase(target);
	problems[target.G].erase(target);
}

void Recommend(int G, int x)
{
	if (x == -1) cout << problems[G].begin()->P << "\n";
	else if (x == 1) cout << problems[G].rbegin()->P << "\n";
}

void Recommend2(int x) { Recommend(0, x); }

void Recommend3(int x, int L)
{
	if (x == -1)
	{
		auto it = problems[0].upper_bound({ 0,L,0 });
		if (it != problems[0].begin())
		{
			--it;
			if (it->L >= L)
			{
				if (it == problems[0].begin())
				{
					cout << "-1\n";
					return;
				}
				--it;
			}
			cout << it->P << "\n";
		}
		else cout << "-1\n";
	}
	else if (x == 1)
	{
		auto it = problems[0].lower_bound({ 0,L,0 });
		if (it != problems[0].end()) cout << it->P << "\n";
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