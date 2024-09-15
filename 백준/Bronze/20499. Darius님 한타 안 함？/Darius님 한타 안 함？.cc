#include <iostream>
using namespace std;

int main()
{
    string s; cin >> s;
    string temp = "";
    int kda[3] = {0,};
    int len = 0;
    for(int i =0; i<s.length(); i++)
    {
        if(s[i]=='/')
        {
            kda[len++] = stoi(temp);
            temp = "";
        }
        else temp+= s[i];
    }
    kda[len] = stoi(temp);
    
    if(kda[0]+kda[2]< kda[1] || kda[1] == 0) cout << "hasu";
    else cout << "gosu";
    return 0;
}