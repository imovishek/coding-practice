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
#define forn(x,y) for(int x=1;x<=y;x++)
using namespace std;
typedef long long int lint;
typedef double dbl;

int ara[100007];
int main()
{
    int n,k;
    sf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        sf1(ara[i]);
    for(int i=1;k-i>0;i++)
        k=k-i;
    pf("%d\n",ara[k]);
    return 0;
}
