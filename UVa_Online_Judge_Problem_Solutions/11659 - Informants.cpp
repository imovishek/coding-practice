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
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
vector<int> edge[50];
vector<int> reli[50];
int flag[50];
int maxi = 0;
int n, m;
void dfs(int fs, int u, int  counti, int sig)
{
    int v;
    for(int i = 0;i<edge[u].size();i++)
    {
        v = edge[u][i];
        if(flag[v]==0)
        {
            flag[v]=1;
            dfs(fs, v, counti+reli[u][i], reli[u][i]);
            flag[v] = 0;
        }
        if(fs==v) break;
    }
    if(u!=fs && sig) counti--;
    if(counti>maxi) maxi = counti;
}
int main()
{
    while(sf2(n,m) && (n || m))
    {
        int u, v;
        FOR(i, m)
        {
            sf2(u, v);
            int sig = 1;
            if(v<0){sig = 0; v = -v;}
            edge[u].pb(v);
            reli[u].pb(sig);
        }
        maxi = 0;
        for(int i = 1; i<=n ; i++)
            dfs(i,i, 0, 0);
        pf("%d\n",maxi);
        for(int i = 1; i<=n ; i++) {reli[i].clear(); edge[i].clear();}
    }
    return 0;
}

