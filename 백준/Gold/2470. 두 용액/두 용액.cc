#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int feature[100001]; 

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    size_t N;  cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> feature[i];
    }

    // sort for binary search
    sort(feature, feature + N);

    // if feature has only alkalinity
    if (feature[N-1] <= 0)
    {
        cout << feature[N - 2] << " " << feature[N - 1];
        return 0;
    }

    // if feature has only acidity
    if (feature[0] >=0)
    {
        cout << feature[0] << " " << feature[1];
        return 0;
    }

    // start binary search: target==0
    int leftP, rightP, minSum = 2000000002, tempSum;
    int low = 0, high = N-1;
    while (low <= high)
    {
        tempSum = feature[low] + feature[high];
        if (tempSum == 0)
        {
            leftP = low;
            rightP = high;
            break;
        }
        else if (tempSum > 0)
        {
            if (tempSum < minSum)
            {
                minSum = tempSum;
                leftP = low;
                rightP = high;
            }
            high--;
        }
        else if (tempSum < 0)
        {
            if ( -tempSum < minSum)
            {
                minSum = -tempSum;
                leftP = low;
                rightP = high;
            }
            low++;
        }
        
        if (low == high) high--;
    }

    // return result
    cout << feature[leftP] << " " << feature[rightP];

    return 0;
}