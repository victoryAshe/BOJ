#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int M, N, L;
int launcher[100000];
pair<int, int> animalLoc[100000];
int ans = 0;

bool isShootable(int idx, int a, int b){
	return abs(launcher[idx] - a) + b <= L;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 

	cin >> M >> N >> L;
	for (int i = 0; i < M; i++) cin >> launcher[i];
	for (int i = 0; i < N; i++) cin >> animalLoc[i].first >> animalLoc[i].second;

	sort(launcher, launcher + M);

	for (int i = 0; i < N; i++)
	{
		int a = animalLoc[i].first, b = animalLoc[i].second;
		if (b > L) continue;

		int idx = lower_bound(launcher, launcher + M, a)- launcher;
		if( (idx<M && isShootable(idx, a,b)) 
			|| (idx-1>=0 && isShootable(idx-1, a, b))) ans++;
	}


	cout << ans;

	return 0;
}