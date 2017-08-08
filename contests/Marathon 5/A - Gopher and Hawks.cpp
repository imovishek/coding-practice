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
#define FOR1(i,x)       for(int i=0;i<(x); i++)
#define mx              100007

using namespace std;
typedef long long int lint;
typedef double dbl;
pair<double, double> ara[1007];
double m, t;
int n = 0;
int bfs()
{
    if(ara[0]==ara[1]) return 0;
    int dist[1007];
    mem(dist, -1);
    dist[0] = 0;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if(u==1) return dist[1];
        FOR(i, n)
        {
            if(dist[i]!=-1) continue;
            dbl dis = sqrt((ara[u].fs-ara[i].fs)*(ara[u].fs-ara[i].fs)+(ara[u].sc-ara[i].sc)*(ara[u].sc-ara[i].sc));
            if(dis/m<=t)
            {
                dist[i] = dist[u] + 1;
                Q.push(i);
            }
        }
    }
    return -1;
}
int main()
{
    while(sf("%lf %lf", &m, &t))
    {
        if(m==0 && t==0) return 0;
        string st;
        int pos = 0;
        getchar();
        t*=60;
        char str[1000];
        while(getline(cin, st) && st.size())
        {
            istringstream ss(st);
            ss >> ara[pos].fs ;
            ss >> ara[pos++].sc ;
//            cout << ara[pos-1].fs << ' ' << ara[pos-1].sc << endl;
        }
//        while(gets(str) && strlen(str))
//        {
//            sscanf(str, "%lf%lf", &ara[pos].fs, &ara[pos++].sc);
//            cout << ara[pos-1].fs << ' ' << ara[pos-1].sc << endl;
//        }


        n = pos;
        int ans = bfs();
        if(ans==-1) pf("No.\n");
        else pf("Yes, visiting %d other holes.\n", ans-1);
    }
    return 0;
}














