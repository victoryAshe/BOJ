#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
    int a, b;
    while (cin >> a >> b)  
        nums.push_back(a + b);
    
    for (int x : nums) cout << x << "\n";

    return 0;
}