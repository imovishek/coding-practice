#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pi acos(-1.0)
#define ll long long
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
//    bool operator<(const PT &a)const{
//        vector<ll> X = {round(x), round(y), round(z)};
//        vector<ll> Y = {round(a.x), round(a.y), round(a.z)};
//        return X < Y;
//    }
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
double area = 0.0;
double getArea(PT a, PT b, PT c){
    return fabs(cross(a-b, c-b).val()) / 2.0;
}
bool iswithintriangle(PT a, PT b, PT c, PT d)
{
    double tarea = getArea(a, b, c);
    double another = getArea(a, b, d) + getArea(b, c, d) + getArea(c, a, d);
    return cmp(tarea - another) == 0;
}
double segDist(PT a, PT b, PT c)
{
    if(cmp(dot(b-a, c-a)) < 0) return dist(a, c);
    if(cmp(dot(a-b, c-b)) < 0) return dist(b, c);
    return fabs(cross(b-a, c-a).val() / (b-a).val());
}
double disttotriangle(PT a, PT b, PT c, PT d)
{
    PT norm = cross(b-a, c-a);
    PT ab = b - a;
    PT nw = cross(ab, norm);
    assert(nw.val() != 0.0);
    nw = nw / nw.val();
    if(cmp(dot(nw, d-a)) == 1) return segDist(a, b, d);

    PT bc = c-b;
    nw = cross(bc, norm);
    assert(nw.val() != 0.0);
    nw = nw / nw.val();
    if(cmp(dot(nw, d-b)) == 1) return segDist(b, c, d);

    PT ca = a-c;
    nw = cross(ca, norm);
    assert(nw.val() != 0.0);
    nw = nw / nw.val();
    if(cmp(dot(nw, d-c)) == 1) return segDist(c, a, d);

    double ret = dot(norm, d-a) / norm.val();
    return fabs(ret);
}
struct tri{
    PT a, b, c;
};
vector<tri> convex_hull(vector<PT> p)
{
    vector<tri> ret;
    int n = p.size();
    for(int i = 0; i<n; i++)
    for(int j = i+1; j<n; j++)
    for(int k = j+1; k<n; k++){
        PT norm = cross(p[i]-p[k], p[j]-p[k]);
        vector<PT> coplaner;
        int f = 0;
        for(int l = 0; l<n; l++)
        {
            if(cmp(dot(norm, p[l]-p[k]))==0){
                if(iswithintriangle(p[i], p[j], p[k], p[l]) == false){
                    f = 1;
                    break;
                }
            }
        }
        if(f) continue;
        // code here
        int sig = -2;
        for(int l = 0; l<n; l++)
        {
            int val = cmp(dot(norm, p[l]-p[k]));
            if(val != 0){
                if(sig==-2) sig = val;
                else {
                    if(sig != val){
                        f = 1;
                        break;
                    }
                }
            }
        }
        if(!f){
            area += getArea(p[i], p[j], p[k]);
            ret.push_back({p[i], p[j], p[k]});
        }
    }
    return ret;
}

double segtotriDist(PT a, PT b, PT c, PT d, PT e)
{
    double l = 0, r = 1.0, ret;
    int cnt = 100;
    while(cnt--)
    {
        double mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0;
        double f1 = disttotriangle(a, b, c, d + (e-d) * mid1);
        double f2 = disttotriangle(a, b, c, d + (e-d) * mid2);
        if(f1 < f2){
            r = mid2, ret = f1;
        } else l = mid1, ret = f2;
    }
    return ret;
}

double tritotriDist(PT a, PT b, PT c, PT d, PT e, PT f)
{
    double a1 = segtotriDist(a, b, c, d, e);
    double a2 = segtotriDist(a, b, c, e, f);
    double a3 = segtotriDist(a, b, c, f, d);
    double a4 = segtotriDist(d, e, f, a, b);
    double a5 = segtotriDist(d, e, f, c, b);
    double a6 = segtotriDist(d, e, f, a, c);
    return min(a1, min(a2, min(a3, min(a4, min(a5, a6)))));
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<PT> vt;
        for(int i = 0; i<n; i++)
        {
            PT a;
            a.scan();
            vt.push_back(a);
        }
        area = 0.0;
        vector<PT> ager = vt;
        vector<tri> hull = convex_hull(vt);
        vt.clear();
        scanf("%d", &n);
        for(int i = 0; i<n; i++)
        {
            PT a;
            a.scan();
            vt.push_back(a);
        }
        auto hull2 = convex_hull(vt);
        double mini = DBL_MAX;
    //    cout << fixed << setprecision(10) ;
    //    cout << area << endl;
        for(int i = 0; i<hull2.size(); i++)
            for(int j = 0; j<hull.size(); j++)
                mini = min(tritotriDist(hull[j].a, hull[j].b, hull[j].c, hull2[i].a, hull2[i].b, hull2[i].c), mini);
        printf("%.10f\n", area + mini);
    }
    return 0;
}

