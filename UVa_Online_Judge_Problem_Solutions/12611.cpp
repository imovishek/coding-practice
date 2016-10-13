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
#define pcase(x) printf("Case %d:\n",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    int t,tst=1;
    sf1(t);
    while(t--)
    {
        int r,l,w,mid;
        sf1(r);
        l=r*5;
        w=(l*6)/10;
        mid=w/2;
        int lef=l*45/100;
        int righ=l*55/100;
        pcase(tst++);
        pf("%d %d\n",-lef,mid);
        pf("%d %d\n",righ,mid);
        pf("%d %d\n",righ,-mid);
        pf("%d %d\n",-lef,-mid);

    }
    return 0;
}
