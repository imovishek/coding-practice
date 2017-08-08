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

using namespace std;
typedef long long int lint;
typedef double dbl;

vector<int>edge[1007];
char str[1007];
pair<int ,char> ara[27];
int cnt = 0;
int vis[1007];
void dfs(int u, char ch=0)
{
    if(edge[u].size()==0) return;
    if(vis[u]) return;
    cnt++;
    str[u-1] = ch;
    vis[u] = 1;
    FOR(i, edge[u].size())
        dfs(edge[u][i], ch);
}
int main()
{
    int t, tst = 1;

    sf("%s", str);
    int len = strlen(str);
    for(int i = 2; i<=len; i++)
    {
        if(edge[i].size()==0)
        {
            for(int j = i + i; j<=len ; j+=i)
            {
                edge[i].pb(j);
                edge[j].pb(i);
            }
        }
    }

    for(int i = 0; i<len ; i++){
        ara[str[i] - 'a'].fs++;
        ara[str[i] - 'a'].sc = str[i];
    }
    mem(str, 0);
    sort(ara, ara+26);
    char ch = ara[25].sc;
    int &maxi = ara[25].fs;
    cnt = 0;
    dfs(2, ch);
    if(cnt>maxi) {pf("NO\n"); return 0;}
    if(len!=1)maxi-=cnt;
    queue<char> Q;
    FOR(i, 26)
    {
        while(ara[i].fs--)
            Q.push(ara[i].sc);
    }
    for(int i = 0; i<len ; i++)
        if(!str[i]){
            str[i] = Q.front();
            Q.pop();
        }
    str[len] = 0;
    pf("YES\n");
    pf("%s\n", str);

    return 0;
}














