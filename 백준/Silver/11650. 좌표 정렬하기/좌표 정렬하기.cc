#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    public:
    int x, y;
};

bool compare(const Point& a, const Point& b)
{
    if(a.x == b.x) return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N; cin >> N;
    int x, y; vector<Point> points;
    for(int i = 0; i< N; i++)
    {
        cin >> x >> y;
        Point point;
        point.x = x; point.y = y;
        points.push_back(point);
    }
    sort(points.begin(), points.end(), compare);
    for(Point p : points)
    {
        cout << p.x << " " << p.y << "\n";
    }
    
    return 0;
}