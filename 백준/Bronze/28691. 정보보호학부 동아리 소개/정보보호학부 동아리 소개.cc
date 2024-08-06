#include <iostream>
#include <map>
using namespace std;

map<string, string> nameMap = {
    {"M", "MatKor"},
    {"W", "WiCys"},
    {"C", "CyKor"},
    {"A", "AlKor"},
    {"$", "$clear"}
};

int main()
{
    string first;
    cin >> first;
    cout << nameMap[first] << "\n";
    
    return 0;
}