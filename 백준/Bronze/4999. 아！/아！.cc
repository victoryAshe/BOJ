#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string JaeHwan_ah, doctor_ah;
    cin >> JaeHwan_ah >> doctor_ah;
    if (doctor_ah.length() <= JaeHwan_ah.length()) cout << "go";
    else cout << "no";

    return 0;
}