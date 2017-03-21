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
    int a,ta,b,tb,hh,mm,arive,en=59+23*60;
    sf2(a,ta);
    sf2(b,tb);
    sf("%d:%d",&hh,&mm);
    mm+=hh*60;
    arive=mm+ta;
    int counti=0;
    for(int i=5*60;i<arive && i<=en;i+=b)
    {
        if(i+tb>mm)counti++;

    }
    pf("%d\n",counti);

    return 0;
}
