#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
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
#define pf1(a) printf("%d\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define pinf 2147483647
#define ninf -2147483647
//#define seti(p,x) p|=(1<<x)
//#define check(p,x) (p & (1<<x))
//#define reseti(p,x) p&=(~(1<<x))

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    char ara[1000];
    int t,tst=1;
    sf("%d",&t);
    while(t--)
    {
       int a,b,c;
        sf3(a,b,c);
        pcase(tst++);
       pf("%d\n",max(a,max(b,c)));

    }
    return 0;
}

