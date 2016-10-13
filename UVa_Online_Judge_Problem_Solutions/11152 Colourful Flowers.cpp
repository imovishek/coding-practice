#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int a, b, c;
    while(sf3(a, b, c)==3)
    {
        dbl s = (a+b+c)/2.0;
        dbl area = sqrt(s*(s-a)*(s-b)*(s-c));
        dbl r = area/s;
        dbl R = a*b*c/area/4.0;
        r = pi * r * r;
        dbl v = area - r;
        s = pi * R * R - area;
        pf("%.4lf %.4lf %.4lf\n", s, v, r);
    }
    return 0;
}








