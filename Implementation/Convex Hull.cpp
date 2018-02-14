#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
#define PI acos(-1.00)
struct point{
    ll x, y;
    point(int x, int y) : x (x), y(y) {}
    point(){}
    inline bool operator<(point p) const{
        return x<p.x || (x==p.x && y<p.y);
    }
};
inline ll cross(point O, point A, point B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
inline vector<point> convex_hull(vector<point> P)
{
    int n = P.size(), k = 0;
    vector<point> H(2*n);
    sort(P.begin(), P.end());
    for(int i = 0; i<n; i++)
    {
        while(k>=2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for(int i = n-2, t = k+1; i>=0; i--)
    {
        while(k>=t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}

int main()
{
    return 0;
}
