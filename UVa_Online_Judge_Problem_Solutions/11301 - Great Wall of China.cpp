#include<bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
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
#define inf 214000
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;

int fx[]= {-1,0,0,-1};
int fy[]= {0,1,-1,0};
int flag[5][1007],n;
char grid[5][1007];
int level[5][1007];
pii dir[5][1007];
class comp{
public:
    bool operator() (pii a, pii b) const
    {
        return level[a.fs][a.sc]>level[b.fs][b.sc];
    }
};
bool isvali(int a, int b)
{
    return a<5 && b<n && a>-1 && b>-1 ;
}
int dijkstra(int &x, int &y)
{
    pii u, v;
    FOR(i, 5) FOR(j, n) level[i][j] = inf;
    level[x][y] = 0;
    dir[x][y] = pii(-1,-1);
    priority_queue< pii, vector<pii>, comp> pQ;
    pQ.push(pii(x, y));
    while(!pQ.empty())
    {
        u = pQ.top();
        pQ.pop();
        flag[u.fs][u.sc] = 1;
//        pf("%d, %d:  %d\n",u.fs, u.sc, level[u.fs][u.sc]);
        if(u.sc==n-1){
                x = u.fs;
                y = u.sc;
                return level[u.fs][u.sc];
        }
        FOR(i, 4)
        {
            int a = u.fs + fx[i];
            int b = u.sc + fy[i];
            if(isvali(a, b) && grid[a][b]!='@' && flag[a][b]==0)
            {
                if(level[u.fs][u.sc] + grid[a][b] - '0' < level[a][b]){
                    level[a][b] = level[u.fs][u.sc] + grid[a][b] - '0';
                    pQ.push(pii(a,b));
                    dir[a][b] = u;
//                    pf("%d, %d:  %d\n",a, b, level[a][b]);
                }

            }
        }
    }
    return inf;

}
void pathflag(pii u)
{
    if(dir[u.fs][u.sc]==pii(-1,-1)) return;
    pathflag(dir[u.fs][u.sc]);
    flag[u.fs][u.sc] = 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    char opa[6][4] = {
        "abc",
        "acb",
        "bac",
        "bca",
        "cab",
        "cba"
    };
    while(sf1(n) && n)
    {
        FOR(i, 5) sf("%s",grid[i]);
        vector<int>vt;
        FOR(i, 5){
            if(grid[i][0]=='@') vt.pb(i);
        }
        int mini = inf;
        FOR(i, 6)
        {
            FOR(k, 5)FOR(l, n) flag[k][l] = 0;
            int sum = 0;
            FOR(j, 3)
            {
                int x = vt[opa[i][j]-'a'], y=0;
                sum += dijkstra(x,y);
                FOR(k, 5)FOR(l, n) flag[k][l] = 0;
                pathflag(pii(x, y));
                pf("%d, %d:  %d**\n",x, y, sum);
            }
            mini = min(mini, sum);
        }
        pf("%d\n",mini);
    }
    return 0;
}












