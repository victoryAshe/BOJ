#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_map<string, string> cheer = {
        {"SONGDO", "HIGHSCHOOL"},
        {"CODE", "MASTER"},
        {"2023", "0611"},
        {"ALGORITHM", "CONTEST"}
    };

    string first; cin >> first;
    cout << cheer[first];

    return 0;
}