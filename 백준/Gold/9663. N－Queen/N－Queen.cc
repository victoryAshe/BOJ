#include <iostream>
#include <cmath>
#define MAX 15
using namespace std;

int col[MAX];
int N, result = 0;

// level: 현재 몇 번째 행을 채우고 있는지 기록
bool IsValid(int level) 
{
	for (int i = 0; i < level; i++)
	{
		// 같은 라인 || 대각선 
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;
	}
	return true;
}

void BackTracking(int x)
{
	if (x == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		col[x] = i; // 해당 위치에 퀸을 배치
		
		// 유효하다면 다음행의 퀸 배치, else: 다른 위치로 퀸 배치 변경
		if (IsValid(x)) BackTracking(x + 1);
	}
}

int main()
{
	cin >> N;
	BackTracking(0);
	cout << result;
}