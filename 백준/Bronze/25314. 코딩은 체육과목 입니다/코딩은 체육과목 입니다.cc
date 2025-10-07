#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; N/=4;
    string L = "long ";
    for(int i = 0; i<N; i++) cout << L;
    cout<< "int";
    
    return 0;
}