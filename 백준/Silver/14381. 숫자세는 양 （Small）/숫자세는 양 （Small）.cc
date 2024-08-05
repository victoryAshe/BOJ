#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int caseResult(int caseNum, int dotNum)
{
    if (caseNum == 0) return -1;

    int num = caseNum * dotNum;
    while (true)
    {
        auto it = find(arr.begin(), arr.end(), num % 10);
        if (it == arr.end())
        {
            arr.push_back(num % 10);
        }

        if (arr.size() >= 10)
        {
            arr.clear();
            return caseNum* dotNum;
        }

        if (num / 10 > 0) num /= 10;
        else break;

    }

    return caseResult(caseNum, dotNum+1);
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    int caseNum, result;
    for (int i = 0; i < T; i++)
    {
        cin >> caseNum;
        result = caseResult(caseNum, 1);
        cout << "Case #" << i+1 <<": ";
        if (result == -1) cout << "INSOMNIA\n";
        else cout << result << "\n";
    }

    return 0;
}
