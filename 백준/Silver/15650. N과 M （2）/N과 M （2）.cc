#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; 
    cin >> N >> M;
    
    vector<int> num(N);
    for (int i = 0; i < N; i++) num[i] = i + 1;
    
    vector<bool> choice(N);
    for (int i = 0; i<M; i++) choice[i] = 1;
    
    do {
        for (int i = 0; i < N; i++)
        {
            if (choice[i]) cout << num[i] << " ";
        }
        cout << "\n";
    } while (prev_permutation(choice.begin(), choice.end()));
    

    return 0;
}
