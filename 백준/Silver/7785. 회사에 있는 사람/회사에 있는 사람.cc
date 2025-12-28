#include <iostream>
#include <set>
#include <string>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false); 
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N; 
    std::cin >> N;
    std::set<std::string> people;
    std::string name, order
        , ENTER = "enter", LEAVE = "leave";
    for (int i = 0; i < N; i++)
    {
        std::cin >> name >> order;
        if(order==ENTER)
        {
            people.insert(name);
        }
        else if (order == LEAVE)
        {
            people.erase(name);
        }
    }

    std::stack<std::string> ans;
    for (std::string person : people) ans.push(person);
    int size = ans.size();
    for (int i = 0; i < size; i++)
    {
        name = ans.top();
        ans.pop();
        std::cout << name<<"\n";
    }
  
    return 0;
}