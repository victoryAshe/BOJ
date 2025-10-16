#include <iostream>
#include <array>
using namespace std;

using p = pair<int, array<bool, 10>>;

p team_score[5] =
{	
	//	  A B C D E F G H I J
	{11, {1,1,1,1,1,1,1,1,0,1}},
	{9,  {1,0,1,0,1,1,1,1,1,0}},
	{9,  {1,1,1,0,1,1,1,1,0,0}},
	{8,  {1,0,1,0,1,1,1,1,0,0}},
	{8,  {1,1,1,0,0,1,1,1,0,0}}
};

void Print(int n)
{
	p score = team_score[n];
	cout << score.first << '\n';
	for (int i = 0; i < 10; i++)
	{
		if (score.second[i]) cout << (char)(i + 'A') <<" ";
	}
	cout << "L M";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	if (N == 1) Print(0);
	else if (N < 4) Print(1);
	else if (N == 4) Print(2);
	else if (N < 10) Print(3);
	else Print(4);
	
	return 0;
}