#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define ll long long
#define PI acos(-1.00)
struct PT{
    ll x, y;
    PT(int x, int y) : x (x), y(y) {}
    PT(){}
    inline bool operator<(PT p) const{
        return x<p.x || (x==p.x && y<p.y);
    }
};
inline ll cross(PT O, PT A, PT B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
inline vector<PT> convex_hull(vector<PT> P)
{
    int n = P.size(), k = 0;
    vector<PT> H(2*n);
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
