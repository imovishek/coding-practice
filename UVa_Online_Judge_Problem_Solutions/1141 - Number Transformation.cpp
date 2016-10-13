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
vector<int> factor[1005];
void sieve()
{
    for(int i = 4; i<=1000; i+=2) factor[i].pb(2);
    for(int i = 3; i<1000; i++)
    {
        if(factor[i].size()==0)
            for(int j = i+i; j<=1004; j+=i)
                factor[j].pb(i);
    }
//    for(int i = 950; i<=1000 ; i++){
//        pf("%d = ",i);
//        for(int j = 0; j<factor[i].size(); j++)
//            pf("%d ",factor[i][j]);
//        pf("\n");
//    }
}
int level[1007];
int bfs(int u, int endi)
{
    int v;
    queue<int>Q;
    Q.push(u);
    mem(level, -1);
    level[u] = 0;
    if(u==endi) return 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(int i = 0; i<factor[u].size(); i++)
        {
            int v = factor[u][i] + u;
            if(v < endi && level[v]==-1)
            {
                Q.push(v);
                level[v] = level[u] + 1;
            }
            else if(v==endi)
                return level[u] + 1;
        }
    }
    return -1;
}
int main()
{
    sieve();
    int u, endi;
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf2(u,  endi);
        pcase(tst++);
        pf("%d\n", bfs(u, endi));
    }
    return 0;
}

