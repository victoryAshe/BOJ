#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string herName; int num;
    cin >> herName >> num;
    int herNameLen = herName.length();

    int L = 0, O = 0, V = 0, E = 0;
    int possibility = -1;
    string result;
    
    for (int i = 0; i < herNameLen; i++)
    {
        switch (herName[i])
        {
        case 'L': L++; break;
        case 'O': O++; break;
        case 'V': V++; break;
        case 'E': E++; break;
        }
    }

    for (int i = 0; i < num; i++)
    {
        string teamName; cin >> teamName;
        int tempL = L, tempO = O, tempV = V, tempE = E;
        int teamNameLen = teamName.length();
        for (int j = 0; j < teamNameLen; j++)
        {
            switch (teamName[j])
            {
            case 'L': tempL++; break;
            case 'O': tempO++; break;
            case 'V': tempV++; break;
            case 'E': tempE++; break;
            }
        }

        int tempPossibility = ((tempL + tempO) % 100 * (tempL + tempV) % 100
            * (tempL + tempE) % 100 * (tempO + tempV) % 100 * (tempO + tempE) % 100
            * (tempV + tempE) % 100) % 100;
        if (tempPossibility > possibility)
        {
            possibility = tempPossibility;
            result = teamName;
        }
        else if (tempPossibility == possibility)
        {
            result = result < teamName ? result : teamName;
        }
    }

    cout << result;

    return 0;
}