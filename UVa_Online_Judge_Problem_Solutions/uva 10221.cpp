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
#define pi acos(-1)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    double s,a;
    char ch[10];
    while(sf("%lf %lf %s",&s,&a,ch)!=EOF)
    {
        if(0==strcmp(ch,"deg"))a*=60;
        double arc,cord,angle;
        angle=(double) a/60.0/180*pi;
        s+=6440;
        if(angle>pi)angle=2*pi-angle;
        arc=(s)*angle*1.0;

        cord=(double) sqrt((1-cos(angle))*2*s*s);
        pf("%.6lf %.6lf\n",arc,cord);

    }
    return 0;
}
