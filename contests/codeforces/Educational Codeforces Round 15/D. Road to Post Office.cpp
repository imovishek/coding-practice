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
#define sf1(a) scanf("%I64d",&a)
#define sf2(a,b) scanf("%I64d %I64d",&a,&b)
#define sf3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0; i<x ;i++)
#define inf 2147483647
#define mem(arr, x) memset(arr, x, sizeof(arr))
using namespace std;
typedef long long int lint;
typedef double dbl;

int main()
{
    lint n, k, a, b ,t;
    sf("%I64d",&n);
    lint sq=sqrt(n);
    sf3( k, a, b);
    sf1(t);
    lint seg=(sq/k)*k;
    lint seck=(seg)*a+ seg/k*t;
    lint ans=0;
    while(n>seg){
            if(n*b<seck+(n-seg)*b){ans+=n*b; pf("%I64d\n",ans);return 0;}
            n-=seg;
            ans+=seck;
    }
    while(n>k)
    {
        if(n*b<k*a+t+(n-k)*b){ans+=n*b; pf("%I64d\n",ans);return 0;}
            n-=k;
            ans+=k*a+t;
    }
    if(n>0){
        ans+=n*a;
    }
    pf("%I64d\n",ans);
    return 0;
}
