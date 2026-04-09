#include <iostream>

const int MAX = 200'001;
bool bTimeMachineAvailable[MAX];
int NextAvailableDay[MAX];

int N, K;

bool TisAvailable(int T)
{
    // 출발점.
    int start = N;

    // K번 이동
    for (int i = 0; i < K; i++)
    {
        // 1일로 갔다면
        if (start - T <= 1)
        {
            return true;
        }

        // 지금 가능한 가장 빠른 Timemachine Available 날짜.
        start = NextAvailableDay[start - T];
    }

    return false;
}

int BiniarySearch()
{
    // T의 최솟값을 구하기.
    int low = 0;    // F
    int high = N;   // T

    while (low + 1 < high)
    {
        int mid = (low + high) / 2;

        if (!TisAvailable(mid))
        {
            // 해당 일자가 불가능하면 일자를 넓힘
            low = mid;
        }
        else
        {
            // 해당 일자가 가능하면 일자를 줄임
            high = mid;
        }
    }

    return high;
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    // Input.
    std::cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> bTimeMachineAvailable[i];
    }

    for (int i = N; i >= 1; i--)
    {
        if (bTimeMachineAvailable[i])
        {
            NextAvailableDay[i] = i;
        }
        else NextAvailableDay[i] = NextAvailableDay[i + 1];
    }

    std::cout << BiniarySearch();

    return 0;
}