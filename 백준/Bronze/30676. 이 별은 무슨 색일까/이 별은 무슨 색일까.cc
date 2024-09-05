#include <iostream>
using namespace std;

int main()
{
    int value; cin >> value;
    if(value>=620) cout << "Red";
    else if(value>=590) cout <<"Orange";
    else if(value >=570) cout <<"Yellow";
    else if(value>=495) cout <<"Green";
    else if(value >=450) cout << "Blue";
    else if(value>=425) cout <<"Indigo";
    else if(value>=380) cout << "Violet";
    
    return 0;
}