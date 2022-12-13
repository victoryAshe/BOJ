#include <iostream>
#include <string>
using namespace std;


int main()
{
	int nums[6];
	cin >> nums[0] >> nums[1] >> nums[2]
		>> nums[3] >> nums[4];

	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		if (nums[i] == 0) continue;
		result += nums[i] * nums[i];
	}
	result %= 10;

	cout << result;

	return 0;
}