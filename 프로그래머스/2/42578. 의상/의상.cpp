#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> kinds;
    for (vector<string> x : clothes)
    {
        if (kinds.find(x[1]) != kinds.end()) kinds[x[1]]++;
        else kinds[x[1]] = 1;
    }

    for (auto p : kinds)
    {
        answer *= 1 + p.second;
    }
    answer -= 1;

    return answer;
}