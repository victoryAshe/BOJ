#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mini
{
    int quality; int price;
};

bool compare1(Mini a, Mini b)
{
    if (a.quality == b.quality) return a.price < b.price;
    return a.quality > b.quality;
}

bool compare2(Mini a, Mini b)
{
    if (a.price == b.price) return a.quality > b.quality;
    return a.price < b.price;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<Mini> arr;

    int N; cin >> N;
    int q, p;
    for (int i = 0; i < N; i++)
    {
        cin >> q >> p;
        Mini mini = { q, p };
        arr.push_back(mini);
    }
    sort(arr.begin(), arr.end(), compare1);
    cout << arr[0].quality << " " << arr[0].price << " " << arr[1].quality << " " << arr[1].price << "\n";
    sort(arr.begin(), arr.end(), compare2);
    cout << arr[0].quality << " " << arr[0].price << " " << arr[1].quality << " " << arr[1].price << "\n";


    return 0;
}