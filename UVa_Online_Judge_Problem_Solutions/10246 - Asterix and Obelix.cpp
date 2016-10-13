#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%lld\n",a);
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
lint inf  = 100000000000000007;
lint G[87][87];
int path[87][87];
int feast[87];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n, q, m;
    while(sf3(n, m, q))
    {
        if(n==q && q==m && n==0) return 0;
        if(tst!=1) pf("\n");
        FOR(i, n) FOR(j, n) G[i][j] = inf;
        FOR(i, n) G[i][i] = 0;
        FOR(i, n)
            sf1(feast[i]);
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            G[u-1][v-1] = w;
            G[v-1][u-1] = w;
        }
        FOR(i, n) FOR(j, n) path[i][j] = max(feast[i], feast[j]);
        FOR(k, n)
            FOR(i, n)
                FOR(j, n)
                    if(G[i][j] + path[i][j] > G[i][k] + G[k][j] + max(path[i][k], path[k][j])){
                        G[i][j] = G[i][k] + G[k][j];
                        path[i][j] = max(path[i][k], path[k][j]);
                    }
      FOR(k, n)
            FOR(i, n)
                FOR(j, n)
                    if(G[i][j] + path[i][j] > G[i][k] + G[k][j] + max(path[i][k], path[k][j])){
                        G[i][j] = G[i][k] + G[k][j];
                        path[i][j] = max(path[i][k], path[k][j]);
                    }



        pf("Case #%d\n", tst++);
        FOR(i, q)
        {
            int u, v;
            sf2(u, v);
            u--, v--;
            lint mini = G[u][v] + path[u][v], maxi = max(feast[u], feast[v]);
            if(mini>=inf) pf("-1\n");
            else pf1(mini);
        }
    }
    return 0;
}
/*
7 8 5
2147483647 2147483647 2147483647 2147483647 2147483647 2147483647 2147483647
1 2 200515
1 4 204561
1 5 501651
2 3 1051651
3 4 1051651
3 5 101565165
4 5 151545152
6 7 123546789
1 5
1 6
5 1
3 1
6 7
4 4 2
2 1 8 3
1 2 7
1 3 5
2 4 8
3 4 6
1 4
2 3
0 0 0
*/







