#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int bag[100001]; // [curWeight]:curValue
pair<int, int> stuffs[101]; // W, V
bool comp(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    memset(bag, -1, sizeof(bag));
    int result = 0;
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        int W, V;
        cin >> W >> V;
        stuffs[i] = make_pair(W, V);
    }

    sort(stuffs, stuffs + N + 1, comp);

    for (int i = 1; i <= N; i++)
    {
        pair<int, int> curStuff = stuffs[i];
        if (curStuff.first > K) continue;
        int weightCanHandle = K - curStuff.first;
        for (int j = weightCanHandle; j >=1; j--)
        {
            if (bag[j] == -1) continue;
            int curWeight = j + curStuff.first;
            bag[curWeight] = max(bag[curWeight], bag[j] + curStuff.second);
            result = max(result, bag[curWeight]);
        }
        bag[curStuff.first] = max(bag[curStuff.first], curStuff.second);
        result = max(result, bag[curStuff.first]);
    }

    cout << result;
    return 0;
}