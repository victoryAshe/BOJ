#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num[MAX];
    int sum = -100;
    for (int i = 0; i < MAX; i++)
    {
        cin >> num[i];
        sum += num[i];
    }

    bool isValid[MAX];
    memset(isValid, 1, sizeof(isValid));
    bool isFound = false;
    for (int i = 0; i<MAX; i++)
    {
        if (!isFound)
        {
            int target = sum - num[i];
            int result = find(num+i+1, num + MAX, target) - num;
            if (result < MAX && num[result] == target)
            {
                isValid[i] = false; isValid[result] = false;
                isFound = true;
            }
        }
        
        if(isValid[i]) cout<< num[i] << "\n";
    }

    return 0;
}
