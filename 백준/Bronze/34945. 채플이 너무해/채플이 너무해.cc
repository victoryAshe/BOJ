#include <iostream>
int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    int x; std::cin>>x;
    if(x<6) std::cout << "Oh My God!"; else std::cout<<"Success!";
    return 0;
}