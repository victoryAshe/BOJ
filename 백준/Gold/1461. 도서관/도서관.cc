#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    int result = 0;
    int booksNegative[51] = { 0, };
    int booksPositive[51] = { 0, };
    size_t nLen = 0, pLen = 0;
    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        if (num > 0) booksPositive[pLen++] = num;
        else booksNegative[nLen++] = -num;
    }
    sort(booksNegative, booksNegative + nLen);
    sort(booksPositive, booksPositive + pLen);
    bool isPositiveBigger = booksPositive[pLen - 1] > booksNegative[nLen - 1];
    for (int i =  nLen - 1; i >= 0; i -= M)
    {
        result += booksNegative[i] * 2;
    }
    for (int i =  pLen - 1; i >= 0; i -= M)
    {
        result += booksPositive[i] * 2;
    }
    result -= isPositiveBigger ? booksPositive[pLen - 1] : booksNegative[nLen - 1];
    cout << result;

    return 0;
}