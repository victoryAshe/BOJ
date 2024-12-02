#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX = 200002;

map<string, int> names;
int parent[MAX];
int sizes[MAX];

int find(int i)
{
	if (i == parent[i]) return i;
	return parent[i] = find(parent[i]);
}

void merge(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x == y) return;
	
	if (sizes[x] > sizes[y]) swap(x, y);
	
	parent[x] = y;
	sizes[y] += sizes[x];
}

void Solution()
{
	int F; 
	cin >> F;

	names.clear();
	int nameSize = 0;
	for (int i = 0; i < F; i++)
	{
		string curInput[2];
		for (int j = 0; j < 2; j++)
		{
			cin >> curInput[j];
			if(names.count(curInput[j])==0)
			{
				names[curInput[j]] = nameSize;
				parent[nameSize] = nameSize;
				sizes[nameSize++] = 1;
			}
		}
		merge(names[curInput[0]], names[curInput[1]]);
		cout << sizes[find(names[curInput[0]])] << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) Solution();

	return 0;
}