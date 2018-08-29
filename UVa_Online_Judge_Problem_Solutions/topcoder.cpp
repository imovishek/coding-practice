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
    double x, y, z;
    PT(){x = y = 0; }
    PT(double _x, double _y, double _z) {x = _x, y = _y, z = _z; }
    PT operator-(const PT &a) const{
        return PT(x - a.x, y - a.y, z - a.z);
    }
    PT operator+(const PT &a) const{
        return PT(x + a.x, y + a.y, z + a.z);
    }
    PT operator*(double a) const{
        return PT(x * a, y * a, z * a);
    }
    PT operator/(double a) const{
        return PT(x / a, y / a, z / a);
    }
    double val()
    {
        return sqrt(x * x + y * y + z * z);
    }
    void scan()
    {
        scanf("%lf %lf %lf", &x, &y, &z);
    }
    void print()
    {
        printf("(%.4f, %.4f, %.4f)", x, y, z);
    }
};

double dist(PT a, PT b)
{
    return (a - b).val();
}

double dist2(PT a, PT b)
{
    a = a - b;
    return a.x * a.x + a.y * a.y + a.z * a.z;
}
double dot(PT a, PT b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
PT cross(PT a, PT b)
{
    return PT(a.y * b.z - b.y * a.z, b.x * a.z - a.x * b.z, a.x * b.y - a.y * b.x);
}

bool isClose(PT a, PT va, PT b, PT vb, double r)
{
    double l = 0.0, r = 1000000000.0;
    int cnt = 2000;
    double ret = 0;
    while(cnt--)
    {
        double mid1 = l + (r - l)/3, mid2 = r - (r - l)/3;
        PT a1 = a + va * mid1, b2 = b + vb * mid2;
        PT b1 = b + vb * mid1, a1 = a + va * mid2;
        double dist1 = dist(a1, b1), dist2 = dist(a2, b2);

        if(dist1 <= dist2)
            r = mid2, ret = dist1;
        else l = mid1, ret = dist2;
    }
    if(cmp(ret - r) == 0) return "YES";
    return "NO";
}

int main()
{

    return 0;
}

