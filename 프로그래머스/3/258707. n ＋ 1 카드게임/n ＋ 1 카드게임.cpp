#include <set>
#include <vector>
using namespace std;

// set container: 이진 트리 구조로 인한 빠른 탐색, 삭제 가능. unique key. insert하면 자동 정렬됨

bool MatchCards(set<int>& cards1, set<int>& cards2, int target)
{
    for (int x : cards1)
    {
        auto it = cards2.find(target - x);
        if (it != cards2.end())
        {
            cards1.erase(x);
            cards2.erase(*it);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1, n = cards.size(), initialCnt = n / 3;
    set<int> initial, drawed;
    
    for (int i = 0; i < initialCnt; i++) 
        initial.insert(cards[i]);

    for (int i = initialCnt; i < n; i += 2)
    {
        // 매 round에 살 수 있는 카드르 drawed에 넣어 관리
        drawed.insert(cards[i]);
        drawed.insert(cards[i + 1]);

        // 손에 있는 패로 sum을 만들 수 있는가?
        if (MatchCards(initial, initial, n + 1)) {
            // 코인 소모 X 
        }
        else if (coin >= 1 && MatchCards(initial, drawed, n + 1))
            coin -= 1;
        else if (coin >= 2 && MatchCards(drawed, drawed, n + 1))
            coin -= 2;
        else break;
        answer++;
    }

    return answer;
}