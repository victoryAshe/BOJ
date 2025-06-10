#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


struct compare
{
    bool operator()(pair<int, size_t>& a, pair<int, size_t>& b)
    {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> genres_hit;
    unordered_map <string, priority_queue<pair<int,size_t>, vector<pair<int, size_t>>, compare>> songs;

    size_t songLen = genres.size();
    for (size_t i = 0; i < songLen; i++)
    {
        string curGenre = genres[i];
        if (genres_hit.find(curGenre) != genres_hit.end())
        {
            genres_hit[curGenre] += plays[i];
        }
        else genres_hit[curGenre] = plays[i];

        songs[curGenre].push({ plays[i], i });
    }

    priority_queue<pair<int, string>> genres_Q;
    for (auto p : genres_hit) genres_Q.push({ p.second, p.first });
    while (!genres_Q.empty())
    {
        string curGenre = genres_Q.top().second;
        genres_Q.pop();

        int cnt = 0;
        while (cnt++ < 2 && !songs[curGenre].empty())
        {
            answer.push_back(songs[curGenre].top().second);
            songs[curGenre].pop();
        }
    }

    return answer;
}