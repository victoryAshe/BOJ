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

    
    int half = total / 2;
    int ans = 0;

    int s = 0, e = 0;
    int cur = 0;

    while (s < N) {

        // e를 늘릴 수 있을 때까지 증가
        while (e < s + N && cur + dist[e % N] <= half) {
            cur += dist[e % N];
            e++;
        }

        ans = std::max(ans, cur);

        // s를 한 칸 이동
        cur -= dist[s];
        s++;
    }
    std::cout << ans;

    return 0;
}