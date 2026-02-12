#include <iostream>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    int N; std::cin >> N;

    ll* dist = new ll[N];
    ll total = 0;

    for (int i = 0; i < N; i++)
    {
        std::cin >> dist[i];
        total += dist[i];
    }

    ll* arr = new ll[2 * N + 1];
    for (int i = 0; i < 2 * N; ++i)
    {
        arr[i + 1] = arr[i] + dist[i % N];
    }

    ll half = total / 2;
    ll ans = 0;

    int End = 0;
    for (int Start = 0; Start < N; ++Start)
    {
        if (End < Start) End = Start;

        while (End + 1 <= Start + N && (arr[End + 1] - arr[Start]) <= half)
        {
            End += 1;
        }

        ans = std::max(ans, arr[End] - arr[Start]);
    }

    std::cout << ans;

    return 0;
}