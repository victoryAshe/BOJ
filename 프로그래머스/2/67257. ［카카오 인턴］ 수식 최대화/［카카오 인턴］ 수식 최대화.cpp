#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using ll = long long;

ll solution(std::string expression) {
	ll answer = 0;

	// nums, operator 배열 구성.
	std::vector<ll> nums;
	std::vector<char> operators;

	const int len = static_cast<int>(expression.length());

	std::string num = "";
	for (int i = 0; i < len; i++)
	{
		char c = expression[i];
		if (isalnum(c))
		{
			num = num + c;
		}
		else
		{
			nums.push_back(stol(num));
			num = "";
			operators.push_back(c);
		}
	}
	nums.push_back(stol(num));



	char operatorPriority[3] = {'*', '+', '-'};
	do
	{
		// Calculate by priority.
		std::vector<ll> tempNums = nums;
		std::vector<char> tempOps = operators;
		for (char priority : operatorPriority)
		{
			for (int i = 0; i < static_cast<int>(tempOps.size());)
			{
				if (tempOps[i] == priority)
				{
					ll calculated = tempNums[i];
					if (priority == '*')
					{
						calculated *= tempNums[i + 1];
					}
					else if (priority == '+')
					{
						calculated += tempNums[i + 1];
					}
					else if (priority == '-')
					{
						calculated -= tempNums[i + 1];
					}
					tempNums[i] = calculated;
					tempNums.erase(tempNums.begin() + i + 1);
					tempOps.erase(tempOps.begin() + i);

				}
				else i++;
			}
		}

		answer = std::max(answer, std::abs(tempNums[0]));


	} while (std::next_permutation(operatorPriority, operatorPriority + 3));

	return answer;
}