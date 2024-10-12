#include <iostream>
#include <map>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    map<string, int> people;
    int size = N + M;
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        string s; cin >> s;
        if (people.find(s) == people.end()) people[s] = 1;
        else
        {
            people[s]++;
            result++;
        }
    }

    cout << result << "\n";
    for (auto p : people)
    {
        if (p.second > 1) cout << p.first << "\n";
    }

    return 0;
}