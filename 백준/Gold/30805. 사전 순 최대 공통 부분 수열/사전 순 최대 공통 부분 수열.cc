#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int A[100];
pair<int, int> B[100];
vector<pair<int, int>> sequence;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int K;

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	cin >> M; 
	for (int i = 0; i < M; i++)
	{
		int num; cin >> num;
		B[i] = { -num,i };
	}

	sort(B, B+M);

	int idx = 0;
	for (auto p : B)
	{
		if (sequence.size() > 0 
			&& sequence[sequence.size() - 1].second > p.second) continue;

		int aIdx = find(A + idx, A + N, -p.first) - A;
		if (aIdx == N) continue;
		sequence.push_back(p);
		idx = aIdx+1;
		if (idx >= N) break;
	}
	
	K = sequence.size();
	cout << K;
	if (K > 0)
	{
		cout << "\n";
		for (auto p : sequence)
		{
			cout << -p.first << " ";
		}
	}

	return 0;
}