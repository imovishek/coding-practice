/*input
1 2 4 6
*/

#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9

class Point{
public:
	double x, y;
	Point(){x = 0, y = 0;}
	Point(double x, double y) : x(x), y(y) {}
	Point operator+(const Point a) const{
		return Point(x + a.x, y + a.y);
	}
	Point operator-(const Point a) const{
		return Point(x - a.x, y - a.y);
	}
	Point operator*(const double a) const{
		return Point(x*a, y*a);
	}
	friend double cross(Point a, Point b){
		return a.x*b.y - a.y*b.x;
	}
	friend double dot(Point a, Point b){
		return a.x*b.x + a.y*b.y;
	}
	friend Point unit(Point a)
	{
		double dist = sqrt(a.x*a.x + a.y*a.y);
		return Point(a.x/dist, a.y/dist);
	}
	friend double dist(Point a)
	{
		return sqrt(a.x*a.x + a.y*a.y);
	}
	friend bool isequal(double a, double b)
	{
		if(abs(a-b) < eps) return 1;
		return 0;
	}

};

int main()
{
    Point a, b;
    scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
    Point c = a + unit(b - a) * 3;
    printf("%lf %lf\n", c.x, c.y);
	return 0;
}