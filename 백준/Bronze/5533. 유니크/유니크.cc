#include <iostream>
using namespace std;

int numChecks[101][3];

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    int nums[200][3];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num; cin >> num;
            nums[i][j] = num;
            numChecks[num][j]++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        int score = 0;
        for (int j = 0; j < 3; j++)
        {
            int num = nums[i][j];
            if (numChecks[num][j] == 1) score += num;
        }
        cout << score << "\n";
    }

    return 0;
}