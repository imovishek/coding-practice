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

vector<int> edge[mx];
int col[mx];
int bigflag = 0;
void dfs(int u, int tim, int p)
{
    col[u] = 1;
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!col[v]){
            dfs(v, tim+1, u);
            if(bigflag) return;
        }
        else if(v!=p)
        {
            if(tim==2) bigflag = 1;
        }
    }
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n, m, x;
        sf2(n, m);
        FOR(i, m)
        {
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        FOR(i, n)
        {
            bigflag = 0;
            mem(col, 0);
            dfs(i, 0, -1);
            if(bigflag) break;
        }
        pcase(tst++);
        if(n<3) pf("No\n");
        else if(!bigflag){
            if(m<=2*n-4) pf("No\n");
            else pf("Yes\n");
        }
        else {
            if(m<=3*n-6) pf("No\n");
            else pf("Yes\n");
        }
        FOR(i, n) edge[i].clear();

    }
    return 0;
}













