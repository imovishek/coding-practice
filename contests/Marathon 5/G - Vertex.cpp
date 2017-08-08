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
vector<int> edge[107];
int vis[107];
void dfs(int u, int p)
{
//    if(p==u) vis[u] = 1;
//    pf("%d*\n", u);
    FOR(i, edge[u].size()){
        if(!vis[edge[u][i]]){
            vis[edge[u][i]] = 1;
            dfs(edge[u][i], u);
        }
    }

}

int main()
{
    int t, tst = 1;
    int n;
    while(sf1(n) && n)
    {
        FOR(i, n+1) edge[i].clear();
        int a;
        while(sf1(a) && a)
        {
            int b;
            while(sf1(b) && b)
                edge[a].pb(b);
        }
        sf1(a);
        FOR(i, a){
            mem(vis, 0);
            stringstream ss;
            int st, ans = 0;
            sf1(st);
            dfs(st, -1);
            vector<int> vt;
            FOR1(i, n) if(vis[i]==0) {ss << ' ' << i; ans++;}
            cout << ans << ss.str() << endl;

        }

    }

    return 0;
}


/*

3
1 2 0
2 3 0
3 1 3 0
0
2 1 2

*/











