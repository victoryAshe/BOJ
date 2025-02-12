#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int sushi[30000];
int check[3001];

int main()
{ 
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, d, k, c;
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) cin >> sushi[i];
	
	int duplicates = 0, maxKind = 0;
	bool isCouponValid = true;

	for (int i = 0; i < N; i++)
	{
		duplicates = 0; // 중복 스시 체크
		isCouponValid = true;
		for (int j = i; j < i + k; j++)
		{
			if (check[sushi[j % N]]) duplicates++; // 이미 먹은 초밥이면 중복 수++
			else check[sushi[j % N]] = true;

			if (sushi[j % N] == c) isCouponValid = false;
		}
		maxKind = max(maxKind, k - duplicates + isCouponValid);
		memset(check, 0, sizeof(check));
	}

	cout << maxKind;

	return 0;
}