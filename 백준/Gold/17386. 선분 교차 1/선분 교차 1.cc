#include <iostream>
using namespace std;

typedef pair<long long, long long> Point;
typedef pair<Point, Point> Segment;

long long ccw(Point p1, Point p2, Point p3)
{
	long long ret = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
		- (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
	if (ret < 0) return -1;
	if (ret > 0) return 1;
	return 0;
}

bool isIntersect(Segment s1, Segment s2)
{
	Point p1 = s1.first, p2 = s1.second;
	Point p3 = s2.first, p4 = s2.second;

	long long p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	long long p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0)
	{
		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		return (p2 >= p3 && p4 >= p1);
	}

	return (p1p2 <= 0 && p3p4 <= 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Segment s1, s2;
	cin >> s1.first.first >> s1.first.second >> s1.second.first >> s1.second.second;
	cin >> s2.first.first >> s2.first.second >> s2.second.first >> s2.second.second;

	cout << isIntersect(s1, s2);

	return 0;
}