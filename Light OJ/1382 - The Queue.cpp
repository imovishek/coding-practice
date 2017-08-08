/*
OVISHEK PAUL, CSE - 15, SUST

*/

#include<bits/stdc++.h>
#define pii             pair<lint,lint>
#define mkp             make_pair
#define fs              first
#define sc              second
#define pb              push_back
#define ppb             pop_back()
#define pf              printf
#define pf1(a)          printf("%lld\n",a)
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
#define mx              1007

using namespace std;
typedef long long int lint;
typedef double dbl;
lint fact[1007];
vector<int> edge[mx];
int vis[mx];
lint bigmod(lint a, lint p)
{
    if(p==0) return 1;
    if(p&1) return (a*bigmod(a, p-1)) % MOD;
    lint mo = bigmod(a, p/2);
    return (mo*mo) % MOD;
}

pii dfs(int u)
{
    vis[u]=1;
//    pf("%d*\n", u);
    pii temp = mkp(0, 1);
    FOR(i, edge[u].size())
    {
        int v = edge[u][i];
        if(!vis[v]){
            pii now = dfs(v);
//            pf("%d %d %d**\n", v, now.fs, now.sc);
            temp.sc = (((fact[temp.fs+now.fs] * temp.sc)%MOD)*now.sc)%MOD;
//            pf("*** %d %d##\n", u, temp.sc);
            temp.sc = (temp.sc * bigmod((fact[temp.fs] * fact[now.fs]) % MOD, MOD-2)) % MOD;
            temp.fs+=now.fs;
        }
    }
//    pf("*** %d %d\n", u, temp.sc);
    temp.fs++;
    return temp;
}

int main()
{
    int t, tst = 1;
    fact[0] = 1;
    FOR1(i, mx-1) fact[i] = (fact[i-1] * i) % MOD;
    int n;
    sf1(t);
    while(t--)
    {
        sf1(n);
        int ind[n+1];
        mem(ind, 0);

        FOR(i, n-1){
            int u, v;
            sf2(u, v);
            edge[u].pb(v);
            ind[v]++;
        }
        pii ans;
        FOR1(i, n) if(ind[i]==0){
            ans = dfs(i);
            break;
        }
        pcase(tst++);
        pf1(ans.sc);
        FOR1(i, n) edge[i].clear();
        mem(vis, 0);
    }

    return 0;
}














