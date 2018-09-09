/*input
2
1 1 5 5 1
3 3
1 1 5 5 4
1 3
3 1
3 5
5 3

*/

#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-6
#define pi acos(-1.0)
#define ll long long
int cmp(double x)
{
    if(fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}
struct PT{
    double x, y;
    PT(){x = y = 0; }
    PT(double _x, double _y) {x = _x, y = _y; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y);
    }
    PT operator*(double a) const{
        return PT(x * a, y * a);
    }
    PT operator/(double a) const{
        return PT(x / a, y / a);
    }
    double val()
    {
        return sqrt(x * x + y * y);
    }
    PT unit()
    {
        return (*this) / val();
    }
    void scan()
    {
        scanf("%lf %lf", &x, &y);
    }
    void print()
    {
        printf("(%.4f, %.4f)", x, y);
    }
};
struct line{
    double a, b, c;
};

double dist(PT a, PT b)
{
    return (a - b).val();
}

double dist2(PT a, PT b)
{
    a = a - b;
    return a.x * a.x + a.y * a.y;
}
double dot(PT a, PT b)
{
    return a.x * b.x + a.y * b.y;
}
double cross(PT a, PT b)
{
    return a.x * b.y - a.y * b.x;
}
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
PT RotateCW(PT p, double t)
{
    return PT(p.x*cos(t)+p.y*sin(t), -p.x*sin(t)+p.y*cos(t));
}
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R)
{
    vector<PT> ret;
    double d = sqrt(dist2(a, b));
    if (d > r+R || d+min(r, R) < max(r, R)) return ret;
    double x = (d*d-R*R+r*r)/(2*d);
    double y = sqrt(r*r-x*x);
    PT v = (b-a)/d;
    ret.push_back(a+v*x + RotateCCW90(v)*y);
    if (y > 0)
        ret.push_back(a+v*x - RotateCCW90(v)*y);
    return ret;
}
struct Circle
{
	PT c;
	double r;

	void scan()
	{
		c.scan();
		scanf("%lf", &r);
	}
};
double distFromSeg(PT a, PT b, PT c)
{
	if(dot(b-a, c-a) < 0) return dist(c, a);
	if(dot(a-b, c-b) < 0) return dist(c, b);
	if(cmp((b-a).val()) == 0) while(1);
	return fabs(cross(b-a, c-a)) / (b-a).val();
}
bool doesIntersect(Circle c, PT a, PT b)
{
	if(cmp(distFromSeg(a, b, c.c) - c.r) < 0) return true;
	return false;
}

vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r)
{
    vector<PT> ret;
    b = b-a;
    a = a-c;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    if (D < -EPS) return ret;
    ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
    if (D > EPS)
        ret.push_back(c+a+b*(-B-sqrt(D))/A);
    return ret;
}
PT lowl, upr;
int n;
PT ara[300];

inline bool isinside(PT a)
{
	if(cmp(a.x - lowl.x) < 0 || cmp(a.y - lowl.y) < 0 || cmp(upr.x - a.x) < 0 || cmp(upr.y - a.y) < 0)
		return false;
	return true;
}
inline bool check(PT a, int R)
{
	for(int i = 0; i<n; i++)
	{
		if(cmp(dist(ara[i], a) - 1.0 * R) < 0) return false;
	}
	return true;
}
pair<PT, PT> rec[4];
inline bool isok(int R)
{
	for(int i = 0; i<4; i++)
		if(check(rec[i].first, R*1.0)) return false;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<4; j++)
		{
			vector<PT> vt = CircleLineIntersection(rec[j].first, rec[j].second, ara[i], R*1.0);
	// cout << "hi " << j << endl;
			for(PT tm : vt)
				if(isinside(tm) && check(tm, R*1.0)) {
					// tm.print();
					return false;
				}
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++)
		{
			vector<PT> vt = CircleCircleIntersection(ara[i], ara[j], R*1.0, R*1.0);
			for(PT tm : vt)
				if(isinside(tm) && check(tm, R*1.0)) return false;
		}
	}
	return true;
}

int main()
{
	int t;
	int tst = 1;
	scanf("%d", &t);
	while(t--)
	{
		lowl.scan();
		upr.scan();
		rec[0] = {PT(lowl.x, lowl.y), PT(upr.x, lowl.y)};
		rec[1] = {PT(upr.x, lowl.y), PT(upr.x, upr.y)};
		rec[2] = {PT(upr.x, upr.y), PT(lowl.x, upr.y)};
		rec[3] = {PT(lowl.x, upr.y), PT(lowl.x, lowl.y)};
		scanf("%d", &n);
		for(int i = 0; i<n; i++)
			ara[i].scan();
		int l = 1, r = (int) 2e9;
		// cout << isok(3) << endl;
		while(l <= r)
		{
			int mid = l + (r-l)/2;
			if(isok(mid)){
				r = mid - 1;
			} else l = mid + 1;
		}
		printf("Case #%d: %d\n", tst++, r+1);
	}
	return 0;
}