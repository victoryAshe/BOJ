#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    unordered_map<string, string> seminars =
    {
        {"Algorithm", "204"},
        {"DataAnalysis", "207"},
        {"ArtificialIntelligence", "302"},
        {"CyberSecurity", "B101"},
        {"Network", "303"},
        {"Startup", "501"},
        {"TestStrategy", "105"}
    };

    int N;
    cin >> N;

    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        cout << seminars[s] << '\n';
    }

    return 0;
}