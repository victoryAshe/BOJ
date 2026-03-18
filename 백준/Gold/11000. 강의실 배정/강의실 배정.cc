#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int MAX = 200'001;
using P = std::pair<int, int>;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int N, S, T;

    std::cin >> N;
    std::vector<P> schedule(N, { 0,0 });

    for (int i = 0; i < N; i++)
    {
        std::cin >> S >> T;
        P cur = { S,T };
        schedule[i] = cur;
    }

    sort(schedule.begin(), schedule.begin() + N);

    std::priority_queue<int> PQ;
    PQ.push(-schedule[0].second);
    for (int i = 1; i < N; i++)
    {
        const P& curSchedule = schedule[i];
        int mostFastEnd = -PQ.top();
        
        if (mostFastEnd <= curSchedule.first)
        {
            PQ.pop();
        }
        PQ.push(-curSchedule.second);
    }

    std::cout << PQ.size();

    return 0;
}