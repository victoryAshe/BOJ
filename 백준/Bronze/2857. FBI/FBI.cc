#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    string findTag = "FBI";
    string code; int found = 0;
    for(int i = 1; i<6; i++)
    {
        cin >> code;
        if(code.find(findTag)!=string::npos)
        {
            cout << i << " ";
            found++;
        }
    }
    if(found==0) cout << "HE GOT AWAY!\n"; 
    
    
    return 0;
}