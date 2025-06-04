#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int cnt = 0;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) cin >> nums[i];
    int v; cin >> v;
    cout << count(nums.begin(), nums.end(), v);
    return 0;
}