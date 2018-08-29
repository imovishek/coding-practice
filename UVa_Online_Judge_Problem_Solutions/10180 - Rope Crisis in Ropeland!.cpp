#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pi acos(-1.0)
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
    void scan()
    {
        scanf("%lf %lf", &x, &y);
    }
    void print()
    {
        printf("(%.4f, %.4f)", x, y);
    }
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
pair<PT, PT> getTwoPoint(PT a, double r)
{
    PT orgia = a;
    a = a * -1.0;
    double ao = a.val();
    double xo = r;
    double angle = asin(xo/ao);
    double ax = sqrt(ao*ao - xo*xo);
    PT rot;
    rot = RotateCCW(a, angle);
    rot = rot / rot.val() * ax;
    pair<PT, PT> ret;
    ret.first = orgia + rot;

    rot = RotateCCW(a, -angle);
    rot = rot / rot.val() * ax;

    ret.second = orgia + rot;
    return ret;
}

double arcDist(PT a, PT b, double r)
{
    double angle = atan2(cross(a, b), dot(a, b));
    if(angle < 0) angle += 2 * pi;
    return min(r * angle, r * (2*pi - angle));
}

double getDist(PT a, PT ta, PT b, PT tb, double r)
{
    return dist(a, ta) + dist(tb, b) + arcDist(ta, tb, r);
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c)
{
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        PT a, b; a.scan(); b.scan();
        double r;
        scanf("%lf", &r);
        double ans = 100000000000.0;

        double minDist = DistancePointSegment(a, b, PT(0, 0));
        if(cmp(minDist - r) >= 0) ans = dist(a, b);
        else{
            auto ta = getTwoPoint(a, r);
            auto tb = getTwoPoint(b, r);
//            ta.first.print();
//            ta.second.print();
//            tb.first.print();
//            tb.second.print();
            ans = getDist(a, ta.first, b, tb.first, r);
            ans = min(ans, getDist(a, ta.second, b, tb.first, r));
            ans = min(ans, getDist(a, ta.first, b, tb.second, r));
            ans = min(ans, getDist(a, ta.second, b, tb.second, r));
        }
        printf("%.3f\n", ans);

    }
    return 0;
}
