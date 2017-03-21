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
    int n,m;
   sf("%d %d",&n,&m);


        int ara[n+1];
        memset(ara,0,sizeof(ara));
        while(m--)
        {
            int u,v,a;
            sf("%d %d %d",&u,&v,&a);
            for(int i=u; i<=v; i++)
                ara[i]+=a;
        }
        int t;
        sf("%d",&t);
        while(t--)
        {
            int pos;
            sf("%d",&pos);
            pf("%d\n",ara[pos]);
        }

    return 0;
}
