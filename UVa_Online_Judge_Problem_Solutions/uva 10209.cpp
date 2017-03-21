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
using namespace std;
typedef long long int lint;
typedef double dbl;

int main()
{
    double a;
    while(sf("%lf",&a)!=EOF)
    {
        if(a==0){pf("0.000 0.000 0.000\n");continue;}
        double b,sq,angle,tri,sq3=sqrt(3),extra,x,y,z,mid;
        b=sqrt((a-(sq3*a/2)-a/2)*(a-(sq3*a/2)-a/2)+(sq3*a/2-a/2)*(sq3*a/2-a/2));
        angle=acos((a*a*2-b*b)/(2*a*a));
        tri=.5*sin(angle)*a*a;
        extra=a*a/2*angle-tri;
        x=extra*4+b*b;
        extra=a*a-acos(-1)*a*a/4;
        mid=a*a-2*extra;
        y=(mid-x)/2;
        z=(extra-y)*2;
        y*=4;
        pf("%.3lf %.3lf %.3lf\n",x,y,z);
    }
    return 0;
}
