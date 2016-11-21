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
#define For(i,x) for(int i=1;i<=(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;

int graph[105][105];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int u, v;
    while(sf2(u, v))
    {
        if(!u && !v) return 0;
        For(i, 101)
            For(j, 101)
                if(i==j)graph[i][j] = 0;
                else graph[i][j] = inf;
        graph[u][v] = 1;
        while(sf2(u, v))
        {
            if(!u && !v) break;
            graph[u][v] = 1;
        }
        For(k, 100)
            For(i, 100)
                For(j, 100)
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

        int sum = 0, cnt = 0;
        For(i, 100)
            For(j, 100)
                if(graph[i][j]!=inf && graph[i][j])
                {
                    sum+=graph[i][j];
                    cnt++;
                }
        pcase(tst++);
        pf("average length between pages = %.3lf clicks\n",(1.0*sum)/cnt);
    }
    return 0;
}









