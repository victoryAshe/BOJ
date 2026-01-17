#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::string s, endString = "*";
       
    while (true)
    {
        getline(std::cin, s);
        if (s==endString) break;

        int alpha[26] = { 0, };

        int len = s.length();
        for (int i = 0; i<len; i++)
        {
            char c = s[i];
            if (c >= 'a' && c <= 'z')
                alpha[c - 'a'] += 1;
        }

        int res = 0;
        for(int x: alpha)
        {
            if (x == 0) res++;
        }
        std::cout << (res==0 ? "Y" : "N") << "\n";
    }

    return 0;
}