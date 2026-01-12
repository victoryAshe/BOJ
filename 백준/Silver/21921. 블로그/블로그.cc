#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> visitor(N + 1);
    for (int i = 0; i < N; i++) std::cin >> visitor[i];

    int largest = 0, largestCnt = 0, curSum = 0;
    for (int i = 0; i < X; i++) curSum += visitor[i];
    for (int i = X; i <= N; i++)
    {
        if (largest < curSum)
        {
            largest = curSum;
            largestCnt = 1;
        }
        else if (largest == curSum) largestCnt += 1;
        curSum += visitor[i] - visitor[i - X];
    }

    if (largest == 0) std::cout << "SAD";
    else std::cout << largest << "\n" << largestCnt;

    return 0;
}