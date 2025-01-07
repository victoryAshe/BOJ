#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<pair<int,int>> towers;
string answer = "0 ";
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int height;
	cin >> height;
	towers.push({1, height});

	for (int i = 2; i <= N; i++)
	{
		cin >> height;
		if (height < towers.top().second)
		{
			answer += to_string(towers.top().first) + " ";
		}
		else
		{
			while (!towers.empty() && towers.top().second < height)
			{
				towers.pop();
			}
			if (towers.empty()) answer += "0 ";
			else answer += to_string(towers.top().first) + " ";
		}
		towers.push({ i,height });
	}

	cout << answer;
	
	return 0;
}