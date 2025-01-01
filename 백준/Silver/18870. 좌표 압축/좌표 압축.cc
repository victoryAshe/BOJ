#include <iostream>
#include <queue>
using namespace std;

pair<int, int> nums[1000001];

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i].first;
        pq.push({ -nums[i].first, i });
    }

    int order = 0;
    while (!pq.empty())
    {
        int num = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if (pq.size() > 0 && num == -pq.top().first)
        {
            nums[idx].second = order;
        }
        else  nums[idx].second = order++;
    }

    for (int i = 0; i < N; i++)
    {
        cout << nums[i].second << " ";
    }

    return 0;
}