#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;
double calr(double R, int n)
{
    double rot;
    rot=sqrt((1-cos(2*pi/n))/2);
    return rot*R/(rot+1);
}
int main()
{
    int R,n;
    while(sf("%d %d",&R,&n)!=EOF)
    {
        if(R==0){pf("0.0000000000 0.0000000000 0.0000000000\n");continue;}
        if(n==1){pf("%d.0000000000 0.0000000000 0.0000000000\n",R);continue;}
        double angle=2*pi/n*1.0,r=calr((double)R,n);
        double tri=.5*sin(angle)*(R-r)*(R-r);
        double angle2=(pi-angle)/2,area2;
        area2=n*(tri-2*(r*r/2*angle2));
        double area3=pi*R*R-area2-n*(pi*r*r);
        pf("%.10lf %.10lf %.10lf\n",r,area2,area3);
    }
    return 0;
}
