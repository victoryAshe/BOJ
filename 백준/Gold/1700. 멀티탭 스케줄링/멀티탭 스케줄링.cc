#include <iostream>
using namespace std;

int order[101];
int tap[101];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int answer = 0;
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; i++) cin >> order[i];

	for (int i = 0; i < K; i++)
	{
		bool canPass = false;

		// 이미 꽂혀있으면 pass
		for (int j = 0; j < N; j++)
		{
			if (order[i] == tap[j])
			{
				canPass = true;
				break;
			}
		}
		if (canPass) continue;

		// 빈 곳이 있으면 꽂고 지나가기
		for (int j = 0; j < N; j++)
		{
			if (tap[j] == 0)
			{
				tap[j] = order[i];
				canPass = true;
				break;
			}
		}
		if (canPass) continue;

		// 꽂힌 기기를 빼고 꽂기: 가장 오랫동안 사용 안하는 것을 고른다!
		int pullIdx = -1;    // 멀티탭에서 뺄 자리
		int lastOrder = -1;  // 가장 나중에 스케줄이 잡혀있는 것
		for (int j = 0; j<N; j++)
		{
			int curLast = 0;
			for (int m = i + 1; m < K; m++)
			{
				if (tap[j] == order[m]) break; // 다음 순서 중 해당 기기가 있으면 확인 종료
				curLast++;
			}
			if (curLast > lastOrder)
			{
				pullIdx = j;
				lastOrder = curLast;
			}
		}

		tap[pullIdx] = order[i];
		answer++;
	}

	cout << answer;

	return 0;
}