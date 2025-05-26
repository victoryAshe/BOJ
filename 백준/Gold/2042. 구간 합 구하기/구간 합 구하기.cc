#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
const int MAX = 1'000'001;
ll num[MAX];
vector<ll> SegmentTree;

ll Make_SegmentTree(int Node, int Start, int End)
{
    if (Start == End) return SegmentTree[Node] = num[Start];

    int Mid = (Start + End) / 2;
    ll LeftResult = Make_SegmentTree(Node * 2, Start, Mid);
    ll RightResult = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);

    return SegmentTree[Node] = LeftResult + RightResult;
}

void Update_SegmentTree(int Node, int Start, int End, int Index, ll Diff)
{
    if (Index < Start || Index > End) return;
    SegmentTree[Node] += Diff;

    if (Start != End)
    {
        int Mid = (Start + End) / 2;
        Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
        Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
    }
}

ll Sum(int Node, int Start, int End, int Left, int Right)
{
    if (Left > End || Right < Start) return 0;
    if (Left <= Start && End <= Right) return SegmentTree[Node];

    int Mid = (Start + End) / 2;
    ll LeftResult = Sum(Node * 2, Start, Mid, Left, Right);
    ll RightResult = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
    return LeftResult + RightResult;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K; 
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> num[i];

    int treeHeight = ceil(log2(N));
    int treeSize = 1 << (treeHeight + 1);
    SegmentTree.resize(treeSize);
    Make_SegmentTree(1, 0, N-1);
    
    ll a, b, c;
    for (int t = 0; t < M + K; t++)
    {
        cin >> a >> b >> c;
        b--;
        if (a == 1)
        {
            ll Diff = c - num[b];
            num[b] = c;
            Update_SegmentTree(1, 0, N - 1, b, Diff);
        }
        else if (a == 2)
        {
            cout << Sum(1, 0, N - 1, b, c - 1) << "\n";
        }
    }

    return 0;
}