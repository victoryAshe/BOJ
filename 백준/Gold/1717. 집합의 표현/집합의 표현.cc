#include <iostream>
using namespace std;

int nodes[1000002];
int depth[1000002];

int find(int i)
{
    if(i == nodes[i]) return i;
    return nodes[i] = find(nodes[i]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a== b) return;
    
    if(depth[a]>depth[b]) swap(a,b);
    nodes[a] = b;
    if(depth[a] == depth[b]) depth[b]++;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, m; cin >> n >> m;
    for(int i = 0; i<=n; i++) 
    {
        nodes[i] = i;
        depth[i] = 1;
    }
    
    int command;
    int a, b;
    for(int i = 0; i<m; i++)
    {
        cin >> command >> a >> b;
        if(command==0)        // A∪B  
        {
            merge(a,b);
        }
        else                  // A와 B가 같은 집합에 있는지 ? YES : NO
        {
            if(find(a)==find(b))
            {
                cout << "YES\n";
            }
            else cout <<"NO\n";
        }
    }
    
    return 0;
}