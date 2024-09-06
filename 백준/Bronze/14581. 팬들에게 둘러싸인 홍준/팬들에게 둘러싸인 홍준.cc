#include <iostream>
using namespace std;

int main()
{
    string id; cin >> id;
    string fan = ":fan:";
    for(int i = 0; i<3; i++)cout << fan;
    cout <<"\n";
    cout << fan << ":"<<id << ":" <<fan<<"\n";
    for(int i = 0; i<3; i++) cout << fan;
    
    return 0;
}