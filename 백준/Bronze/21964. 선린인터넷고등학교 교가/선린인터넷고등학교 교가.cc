#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N; cin >> N;
    string s; cin >> s;
    cout << s.substr(N-5);
    return 0;
}