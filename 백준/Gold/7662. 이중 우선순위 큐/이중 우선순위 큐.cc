#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T; cin >> T;
	while (T--)
	{
		priority_queue<int, vector<int>> max_pq; // 최대 힙
		priority_queue<int, vector<int>, greater<int>> min_pq; //최소 힙
		map<int, int> mp;  // int 배열로 받을 수 없는 길이라 map으로 처리
		int k; cin >> k;

		for (int i = 0; i < k; i++)
		{
			char order; cin >> order;
			int n; cin >> n;
			if (order == 'I')
			{
				max_pq.push(n);
				min_pq.push(n);
				mp[n]++;
			}
			else
			{
				if (n == 1)
				{
					while (max_pq.empty() == false && mp[max_pq.top()] == 0)
					{
						max_pq.pop();
					}
					if (max_pq.empty()) continue;
					else
					{
						int x = max_pq.top();
						max_pq.pop();
						mp[x]--;
					}
				}
				else
				{
					while (min_pq.empty() == false && mp[min_pq.top()] == 0)
					{
						min_pq.pop();
					}
					if (min_pq.empty()) continue;
					else
					{
						int x = min_pq.top();
						min_pq.pop();
						mp[x]--;
					}
				}
			}
			while (max_pq.empty() == false && mp[max_pq.top()] == 0) max_pq.pop();
			while (min_pq.empty() == false && mp[min_pq.top()] == 0) min_pq.pop();
		}
		if (max_pq.empty()) cout << "EMPTY\n";
		else cout << max_pq.top() << " " << min_pq.top() << "\n";
	}

	return 0;
}