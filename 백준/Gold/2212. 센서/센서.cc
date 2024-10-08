#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, K, result = 0;
    cin >> N >> K;

    vector<int> sensors(N);
    for (int i = 0; i < N; i++)
        cin >> sensors[i];
    sort(sensors.begin(), sensors.end());

    vector<int> sections(N-1);
    for (int i = 1; i < N; i++)
    {
        sections[i - 1] = sensors[i] - sensors[i - 1];
    }
    sort(sections.begin(), sections.end(), greater<int>());
    for (int i = K-1; i < N-1; i++)
        result += sections[i];

    cout << result;
    return 0;
}