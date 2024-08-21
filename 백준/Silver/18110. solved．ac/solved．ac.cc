#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    float n; cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> scores;
    int score;
    for (int i = 0; i < n; i++)
    {
        cin >> score;
        scores.push_back(score);
    }

    sort(scores.begin(), scores.end());
    int skip = round(n * 0.15);
    int _size = n - skip;
    float sum = 0;
    for (int i = skip; i < _size; i++)
    {
        sum += scores[i];
    }
    cout << round(sum / (_size - skip));


    return 0;
}