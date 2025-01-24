#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

struct cmp1 {
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
};

struct cmp2
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

unordered_map<int,int> problems;
priority_queue <pair<int, int>, vector<pair<int,int>>, cmp1> max_q;
priority_queue <pair<int, int>, vector<pair<int, int>>, cmp2> min_q;

void Recommend()
{
    int x;
    cin >> x;

    int p = 0;
    if (x == 1)
    {
        p = max_q.top().second;
        while (problems.find(p) == problems.end() || problems[p]!=max_q.top().first)
        {
            max_q.pop();
            p = max_q.top().second;
        }
    }
    else if (x == -1)
    {
        p = min_q.top().second;
        while (problems.find(p) == problems.end() || problems[p]!= min_q.top().first)
        {
            min_q.pop();
            p = min_q.top().second;
        }
    }

    cout << p << "\n";
}

void Add()
{
    int P, L;
    cin >> P >> L;
    problems[P] = L;
    max_q.push({L, P});
    min_q.push({L, P});
}

void Solve()
{
    int P;
    cin >> P;
    problems.erase(P);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) Add();

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        if (s == "add") Add();
        else if (s == "recommend") Recommend();
        else if (s == "solved") Solve();
    }

    return 0;
}