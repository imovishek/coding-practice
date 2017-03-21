#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
#define FOR1(i,x) for(int i=1;i<=(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int edge[107][107];
int n;
int vis[107];
void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    FOR1(i, n)
    {
        if(edge[u][i]==1)
            dfs(i);
    }
}

int main()
{
    int t, tst = 1;
    while(sf1(n) && n)
    {
        string st;
        mem(edge, 0);
        getchar();
        int cnt = 0;
        while(getline(cin, st) && !(st.size()==1 && st[0]=='0'))
        {
//            puts(st.c_str());
            istringstream ss(st);
            int v, u;
            ss >> u;
            while(ss >> v)
            {
                edge[u][v] = 1;
                edge[v][u] = 1;
            }
        }
        int ara[n+7];
        FOR1(i, n)
        {
            mem(ara, 0);
            FOR1(j, n)
            {
                if(edge[i][j]==1)
                {
                    edge[i][j] = 0;
                    edge[j][i] = 0;
                    ara[j] = 1;
                }
            }
            mem(vis, 0);
            int f = 0;
            FOR1(j, n)
            {
                if(j==i) continue;
                if(!vis[j])
                {
                    f++;
                    dfs(j);
                }
            }
            if(f>1)
            {
//                pf("%d****\n", i);
                cnt++;
            }
            FOR1(j, n)
            {
                if(ara[j]==1)
                {
                    edge[i][j] = 1;
                    edge[j][i] = 1;
                }
            }

        }
        pf1(cnt);
    }
    return 0;
}














