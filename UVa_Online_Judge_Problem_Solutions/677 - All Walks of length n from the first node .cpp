/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<int,int>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define pf              printf
#define pf1(a)          printf("%d\n",a)
#define hi              printf("hi!\n");
#define sf              scanf
#define sf1(a)          scanf("%d",&a)
#define sf2(a,b)        scanf("%d %d",&a,&b)
#define sf3(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a)        scanf("%lld",&a)
#define sf2ll(a,b)      scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x)        printf("Case %d: ",x)
#define MOD             1000000007
#define inf             1000000007
#define pi              acos(-1.0)
#define mem(arr,x)      memset((arr), (x), sizeof((arr)));
#define FOR(i,x)        for(int i=0;i<(x); i++)
#define FOR1(i,x)       for(int i=1;i<=(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> edge[1007];
int n, m, bflag = 0;
vector<int> vt;
int flag[1007];
void rec(int pos, int u)
{
    if(pos==m){
        pf("(1");
        bflag = 1;
        FOR(i, m)
        {
            pf(",%d",vt[i]+1);
        }
        pf(")\n");
        return;
    }
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!flag[v]){
            flag[v] = 1;
            vt.pb(v);
            rec(pos+1, v);
            vt.ppb;
            flag[v] = 0;
        }
    }
}
int main()
{
    int t, tst = 1;
    while(sf2(n, m)==2){

        if(tst!=1) pf("\n");
        tst++;
        FOR(i, n)
            FOR(j, n)
            {
                int a;
                sf1(a);
                if(a) {
                        edge[i].pb(j);
                }
            }
        flag[0] = 1;
        bflag = 0;
        rec(0, 0);
        if(!bflag) pf("no walk of length %d\n", m);
        FOR(i, n) edge[i].clear();
        sf1(n);
    }
    return 0;
}














