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
    int t, tst=1;
    double r,l,w;
    sf1(t);
    while(t-- && sf("%lf %lf %lf",&l,&w,&r))
    {
        double area=l*w;
        double a=acos(-1.0)*r*r;
        dbl biyug=0;
        dbl rad=sqrt(l*l/4.0+w*w/4.0);
        if(l/2.0<r)
        {
            double biu;
            dbl bh=sqrt((r*r-l*l/4.0))*2 ;
            double ar;
            ar=bh*l/4;
            double angle=acos((r*r*2-bh*bh)/(2*r*r));
            biyug+=((a/(2*acos(-1.0))*angle)-ar)*2;

        }
        if(w/2.0<r)
        {
            double biu;
            dbl bh=sqrt((double)(r*r-w*w/4.0))*2 ;
            double ar;
            ar=.5*bh*w/2;
            double angle=acos((r*r*2-bh*bh)/(2*r*r));
            biyug+=((a/(2*acos(-1.0))*angle)-ar)*2;
        }
        if(r>=rad){a=area;biyug=0;}
        a-=biyug;
        pcase(tst++);
        pf("%.6lf\n",a);
    }
    return 0;
}
/*
200 100 80
60 120 100
60 100 120
*/
