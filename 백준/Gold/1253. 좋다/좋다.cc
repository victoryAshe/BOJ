#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2001;
int A[MAX];
int N;

int binarySearch(int i, int j, int target)
{
    int low = 1, high = N;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == A[mid] && mid != i && mid != j)
            return mid;

        if (target < A[mid]) high = mid - 1;
        else if (target >= A[mid]) low = mid + 1;
    }
    return -1;
}

int main()
{
    cin >> N;
    int good = 0;
    for (int i = 1; i <= N; i++) cin >> A[i];
    sort(A+1, A + N);
    bool isFound = false;
    for (int i = 1; i <= N; i++)
    {
        if (A[i] == A[i - 1] && isFound)
        {
            good++; continue;
        }
        isFound = false;
        for (int j = 1; j <= N; j++)
        {
            if (i == j) continue;
            int target = A[i] - A[j];
            if (binarySearch(i, j, target) !=-1)
            {
                isFound = true;
                break;
            }
        }
        if (isFound) good++;
    }
    cout << good;

    return 0;
}