#include <iostream>
#include <map>
using namespace std;

map<string, string> nameMap = { 
    { "NLCS", "North London Collegiate School"},
    { "BHA" , "Branksome Hall Asia"},
    { "KIS" , "Korea International School"},
    {  "SJA" , "St. Johnsbury Academy"} 
};

int main()
{
    string schoolName;
    cin >> schoolName;
    cout << nameMap[schoolName] << "\n";

    return 0;
}