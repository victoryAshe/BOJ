#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using ll = long long;
const ll MAX = 9'876'543'211;

std::vector<ll> arr;
void Solution(std::string numString, int curNum)
{
    if (curNum >= 10) return;

    numString = (char)(curNum + '0') + numString;
    ll num = stoll(numString);
    if (num > MAX) return;
    
    arr.emplace_back(num);

    for (int i = 1; i < 10 - curNum; i++)
    {
        Solution(numString, curNum + i);
    }

}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    for (int i = 0; i < 10; i++)
    {
        Solution("", i);
    }

    sort(arr.begin(), arr.end());

    int N;
    std::cin >> N;
    if (N >= arr.size()) std::cout << "-1";
    else std::cout << arr[N];

    return 0;
}