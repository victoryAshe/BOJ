#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const string& a, const string& b)
{
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    string temp;
    vector<string> arr;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        if (find(arr.begin(), arr.end(), temp) == arr.end())
        {
            arr.push_back(temp);
        }
    }

    sort(arr.begin(), arr.end(), compare);
    int count = arr.size();
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}