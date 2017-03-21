#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
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
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int graph[30][30];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n, m;
    while(sf2(n,m))
    {
        if(!m && !n) return 0;
        string name[n], s;
        FOR(i, n)
        {
            cin >> s;
            name[i] = s;
        }
        FOR(i, n)
            FOR(j, n) graph[i][j] = inf;
        FOR(i, n) graph[i][i] = 0;
        FOR(i, m)
        {
            int u, v, w;
            sf3(u, v, w);
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        FOR(k, n)
            FOR(i, n)
                FOR(j, n)
                    graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
        int sum = 0, mini = inf, pos ;
        FOR(i, n)
        {
            sum = 0;
            FOR(j, n)
                sum+=graph[i][j];
            if(mini>sum)
            {
                mini = sum;
                pos = i;
            }
        }
        cout << "Case #" << tst++ << " : " << name[pos] << endl;
    }
    return 0;
}








