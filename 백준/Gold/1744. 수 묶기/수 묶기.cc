#include <iostream>
#include <algorithm>
using namespace std;

int nums[50];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int result = 0;

	for (int i = 0; i < N; i++) cin >> nums[i];
	sort(nums, nums + N);
	
	int posStart = lower_bound(nums, nums + N, 0) - nums;
	int posIdx = posStart;
	int negIdx = 0;

	while (negIdx < posStart)
	{
		if (posIdx - negIdx >= 2)
		{
			result += nums[negIdx] * nums[negIdx+1];
			negIdx++;;
		}
		else if (posStart==N || nums[negIdx] * nums[posIdx] < nums[negIdx] + nums[posIdx])
		{
			result += nums[negIdx];
		}
		else
		{
			result += nums[negIdx] * nums[posIdx];
			posIdx++;
		}
		
		negIdx++;
	}

	posStart = posIdx;
	posIdx = N-1;

	while (posIdx >= posStart)
	{
		if (posIdx > posStart && nums[posIdx]*nums[posIdx-1] > nums[posIdx])
		{
			result += nums[posIdx] * nums[posIdx-1];
			posIdx--;
		}
		else result += nums[posIdx];
		posIdx--;
	}

	cout << result;

	return 0;
}