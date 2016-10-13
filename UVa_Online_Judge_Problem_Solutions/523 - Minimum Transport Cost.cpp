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

int graph[1007][1007];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    getchar();
    getchar();
    int f = 0;
    while(t--)
    {
        string line;
        getline(cin , line);
        istringstream ss(line);
        int n = 0, x;
        while(ss >> x){
                graph[0][n] = x;
                if(x==-1) graph[0][n] = inf;
                n++;
        }
        for(int i = 1; i<n ; i++)
        {
            FOR(j, n)
            {
                sf1(x);
                graph[i][j] = x;
                if(x==-1) graph[i][j] = inf;
            }
        }
        int ara[n];
        int path[n][n];
        FOR(i, n) FOR(j, n) path[i][j] = j;
        FOR(i, n) sf1(ara[i]);
        FOR(k, n)
            FOR(i, n)
                FOR(j, n)
                    if(graph[i][j]>graph[i][k] + graph[j][k])
                    {
                        graph[i][j] = graph[i][k] + graph[j][k] + ara[k];
                        path[i][j] = path[i][k];
                    }

        char str[1000];
        getchar();
        while(gets(str) && str[0])
        {

            if(f) pf("\n");
            int u, v;
            sscanf(str, "%d %d",&u, &v);
            pf("From %d to %d :\nPath: ",u, v);
            u--, v--;
            f = 1;
            pf("%d",u+1);
            int i = u, j = v;
            while(i!=j)
            {
                i = path[i][j];
                pf("-->%d",i+1);
            }
            pf("\n");
            pf("Total cost : %d\n", graph[u][v]);
        }

    }
    return 0;
}









