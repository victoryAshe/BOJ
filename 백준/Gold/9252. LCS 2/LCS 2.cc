#include <iostream>
#include <string>

const int MAX = 1'001;

int dp[MAX][MAX];

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    std::string A, B;
    std::cin >> A >> B;
    
    int lenA = static_cast<int>(A.length());
    int lenB = static_cast<int>(B.length());
    
    for (int i = 1; i <= lenA; i++)
    {
        for (int j = 1; j <= lenB; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int LengthLCS = dp[lenA][lenB];
    std::cout << LengthLCS;



    if (LengthLCS > 0)
    {
        std::string LCS = "";
        int i = lenA, j = lenB;
        while (i > 0 && j > 0)
        {
            if (A[i-1] == B[j-1])
            {
                LCS = A[i-1] + LCS;
                --i; --j;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                     --i;
                else --j;
            }
        }
        std::cout <<"\n" << LCS;
    }

    

    return 0;
}