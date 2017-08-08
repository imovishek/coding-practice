/*input
5
0 0 4 4 0 4 4 0
5 0 7 6 1 0 2 3
5 0 7 6 3 -6 4 -3
2 0 2 27 1 5 18 5
0 3 4 0 1 2 2 5
*/

#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
#define pdd pair< double, double >
class Point{
public:
	double x, y, z;
	Point(){x = 0, y = 0, z = 0;}
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point operator+(const Point a) const{
		return Point(x + a.x, y + a.y, z + a.z);
	}
	Point operator-(const Point a) const{
		return Point(x - a.x, y - a.y, z - a.z);
	}
	Point operator*(const double a) const{
		return Point(x*a, y*a, z*a);
	}
	friend double cross(Point a, Point b){
		return (a.y*b.z - a.z*b.y) - (a.x*b.z - a.z*b.x) + (a.x*b.y - a.y*b.x);
	}
	friend double dot(Point a, Point b){
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}
	friend Point unit(Point a)
	{
		double dist = sqrt(a.x*a.x + a.y*a.y + a.z*b.z);
		return Point(a.x/dist, a.y/dist, a.z/dist);
	}
	friend double dist(Point a)
	{
		return sqrt(a.x*a.x + a.y*a.y + a.z*b.z);
	}
};

bool isequal(double a, double b)
{
	if(abs(a-b) < eps) return 1;
	return 0;
}

