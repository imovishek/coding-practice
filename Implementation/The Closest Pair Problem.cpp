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
double closestPair(int n)
{
	auto comp = [](Point a, Point b){
		if(a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	};
	set<Point, decltype(comp) > st(comp);
	double d = INT_MAX;
	int x = 0;
	for(int i = 0; i<n; i++)
	{
		auto it = st.upper_bound(Point(-1, ara[i].y + d));
		if(it != st.begin()){
			do{
				it --;
				if(abs(it->y - ara[i].y) > d) break;
				d = min(d, dist(ara[i], *it));
			}while(it != st.begin());
		}
		st.insert(ara[i]);
		while(x < i)
		{
			if(ara[i].x - ara[x].x >= d) st.erase(ara[x++]);
			else break;
		}
	}
	return d;
}

int main()
{
	int n;
	while(scanf("%d", &n) && n)
	{
		for(int i = 0; i<n; i++)
			scanf("%lf %lf", &ara[i].x, &ara[i].y);
		sort(ara, ara+n, [](Point a, Point b){return a.x < b.x;});
		double d = closestPair(n);
		if(d - 1e-10 < 10000) printf("%.4lf\n", d);
		else printf("INFINITY\n");
	}
	return 0;
}
