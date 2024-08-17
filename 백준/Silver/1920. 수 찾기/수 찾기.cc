#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, num;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num; nums[i] = num;
    }
    sort(nums.begin(), nums.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        bool isExists = binary_search(nums.begin(), nums.end(), num);
        if (isExists) cout << 1;
        else cout << 0;
        cout << "\n";
    }



    return 0;
}