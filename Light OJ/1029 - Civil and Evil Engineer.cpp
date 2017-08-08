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

int par[107];
int id(int n)
{
    if(par[n]!=n) par[n] = id(par[n]);
    return par[n];
}
struct data{
    int u, v, w;
    bool operator<(const data &a) const{
        return w<a.w;
    }
} edge[100007];
int pos;
int kruskal(){
    int ans = 0;
    FOR(i, pos){
        int x = id(edge[i].u), y = id(edge[i].v);
        if(x!=y){
            par[x] = y;
            ans+=edge[i].w;
        }
    }
    return ans;
}
bool comp(data a, data b)
{
    return !(a<b);
}

int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int n;
        sf1(n);
        getchar();
        string line;
        pos = 0;
        while(1){
            cin >> edge[pos].u;
            cin >> edge[pos].v;
            cin >> edge[pos].w;
            if(!edge[pos].u && !edge[pos].v && !edge[pos].w) break;
            pos++;
        }
        FOR(i, n+1) par[i] = i;
        sort(edge, edge+pos);
        int ans = kruskal() ;
        FOR(i, n+1) par[i] = i;
        sort(edge, edge+pos, comp);
        ans+=kruskal();
        pcase(tst++);
        if(ans&1) pf("%d/%d\n", ans, 2);
        else pf1(ans/2);
    }
    return 0;
}


/*
3

1
0 1 10
0 1 20
0 0 0

3
0 1 99
0 2 10
1 2 30
2 3 30
0 0 0

2
0 1 10
0 2 5
0 0 0
*/











