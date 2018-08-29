/*input
3
0 0
10000 10000
20000 20000
5
0 2
6 67
43 71
39 107
189 140
0
*/

#include <bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define MOD 1000000007

class Point{
public:
	double x, y;
	Point(){x = y = 0;}
	Point(double x, double y){this->x = x, this->y = y;}
} ara[mx];
double dist(Point a, Point b)
{
	double X = a.x - b.x;
	double Y = a.y - b.y;
	return sqrt(X*X + Y*Y);
}
int n;
double closestPair(int b, int e)
{
	if(b==e) return INT_MAX;
	int mid = (b + e) / 2;
	double d1 = closestPair(b, mid), d2 = closestPair(mid+1, e);
	vector<Point> strip;
	double d = min(d1, d2);
	for(int i = b; i<=e; i++)
	{
		if(abs(ara[i].x - ara[mid].x) < d) strip.push_back(ara[i]);
	}
	sort(strip.begin(), strip.end(), [](Point a, Point b){return a.y < b.y;});
	for(int i = 0; i<strip.size(); i++)
	{
		for(int j = i - 1; j>=0; j--)
		{
			if(abs(strip[j].y - strip[i].y) >= d) break;
			d = min(d, dist(strip[i], strip[j]));
		}
	}
	return d;
}

int main()
{
	while(scanf("%d", &n) && n)
	{
		for(int i = 0; i<n; i++)
			scanf("%lf %lf", &ara[i].x, &ara[i].y);
		sort(ara, ara+n, [](Point a, Point b){return a.x < b.x;});
		double d = closestPair(0, n-1);
		if(d - 1e-10 < 10000) printf("%.4lf\n", d);
		else printf("INFINITY\n");
	}
	return 0;
}
