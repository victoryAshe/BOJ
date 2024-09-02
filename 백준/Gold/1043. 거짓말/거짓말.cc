#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;

int find(int u)
{
	if (u == parent[u]) return u;		// 대표 노드 반환
	return parent[u] = find(parent[u]);	// 경로 압축
}

void merge(const vector<int> &party)
{
	for (int i = 0; i < party.size() - 1; i++)
	{
		int x = find(party[i]);
		int y = find(party[i + 1]);
		if (x > y) parent[y] = x;
		else parent[x] = y;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	for (int i = 0; i <= N; i++) parent.push_back(i);

	int result = M;
	if (M != 0)
	{
		int pLen; cin >> pLen;
		vector<int> truth;
		for (int i = 0; i < pLen; i++)
		{
			int num; cin >> num;
			truth.push_back(num);
		}


		// 파티 정보 저장 및 union
		vector<vector<int>> party(M);
		for (int i = 0; i < M; i++)
		{
			int tempLen; cin >> tempLen;
			int num;
			for (int j = 0; j < tempLen; j++)
			{
				cin >> num;
				party[i].push_back(num);
			}
			merge(party[i]);
		}

		for (int i = 0; i < M; i++)
		{
			bool canLie = true;
			for (int k : truth)
			{
				if (find(k) == find(party[i][0]))
				{
					// 같은 파티 사람들을 union 했으므로 모두 체크할 필요 X
					canLie = false;
					break;
				}
			}
			if (canLie == false) result--;
		}
	}

	cout << result;

	return 0;
}