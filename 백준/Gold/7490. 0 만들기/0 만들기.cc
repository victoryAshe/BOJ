#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> ans;

void Recursion(int N, int cur, int sum, std::string res)
{
    if (cur == N + 1)
    {
        if(sum==0) ans.emplace_back(res.substr(1));
        return;
    }

    int next = cur + 1;
    int curSpaceNext = 10 * cur + next;
    
    std::string curString = std::to_string(cur);
    std::string nextString = std::to_string(next);
    
    Recursion(N, cur + 1, sum + cur, res + "+" + curString);
    if (cur <= N - 1) Recursion(N, cur + 2, sum + curSpaceNext, res + "+" + curString + " " + nextString);

    if (cur == 1) return;

    Recursion(N, cur + 1, sum - cur, res + "-" + curString);
    if (cur <= N - 1) Recursion(N, cur + 2, sum - curSpaceNext, res + "-" + curString + " " + nextString);
}

void Solution()
{
    int N; std::cin >> N;

    Recursion(N, 1, 0, "");

    sort(ans.begin(), ans.end());
    for (auto s : ans) std::cout << s << "\n";
    ans.clear();
    
    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;
    while(T--) Solution();

    return 0;
}