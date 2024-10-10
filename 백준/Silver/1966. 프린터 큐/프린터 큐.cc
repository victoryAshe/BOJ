#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M;    cin >> N >> M;

        queue<pair<int, int>> Q; // idx, priority
        vector<int> priorities;
        int curPointer = 0;

        // Input Priorities
        for (int j = 0; j < N; j++)
        {
            int priority; cin >> priority;
            priorities.push_back(priority);
            Q.push(make_pair(j, priority));
        }
        sort(priorities.begin(), priorities.end(), greater<int>());

        // MakeResult(Print)
        int order = 1;
        while(!Q.empty())
        {
            pair<int, int> p = Q.front();
            Q.pop();
            if (p.second == priorities[curPointer])
            {
                if (p.first == M) break;
                curPointer++; order++;
                continue;
            }
            Q.push(p);
        }
        cout << order << "\n";
    }

    return 0;
}