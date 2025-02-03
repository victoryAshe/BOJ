#include <iostream>
#include <cmath>
using namespace std;

void Solution()
{
	pair<int, int> start, end;
	int n;
	int result = 0;

	cin >> start.first >> start.second >> end.first >> end.second >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> c; int r;
		cin >> c.first >> c.second >> r;
		bool isStartInCircle = sqrt(pow(c.first - start.first, 2)+pow(c.second - start.second, 2))<r;
		bool isEndInCircle = sqrt(pow(c.first - end.first, 2) + pow(c.second - end.second, 2)) <r;
        if(isStartInCircle!=isEndInCircle) result++;
	}
	cout << result << "\n";

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	for (int i = 0; i < T; i++) Solution();

	return 0;
}