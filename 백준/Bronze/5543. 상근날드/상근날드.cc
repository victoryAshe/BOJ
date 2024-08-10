#include <iostream>
using namespace std;

int main()
{
    int sangBurger, jungBurger, haBurger, cola, cider;
    cin >> sangBurger >> jungBurger >> haBurger >> cola >> cider;
    cout << min(min(sangBurger, jungBurger), haBurger) + min(cola, cider) - 50;

    return 0;
}