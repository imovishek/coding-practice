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
struct data{
    int x, y, z;
    data(){}
    data(int a, int b, int c)
    {
        x = a, y = b, z = c;
    }
    bool operator == (const data &a) const{
        if(x==a.x && y==a.y && z==a.z) return true;
        return false;
    }

};
int l, r, c;
int isvali(int x, int y, int z)
{
    return x>-1 && y>-1 && z>-1 && x<l && y<r && z<c;
}
int dist[37][37][37];
char grid[37][37][37];
int fx[] = {0,0,0,0,1,-1};
int fy[] = {1,-1,0,0,0,0};
int fz[] = {0,0,1,-1,0,0};
int bfs(data u, data en)
{
    queue<data> Q;
    int x = u.x, y = u.y, z = u.z;
    Q.push(data(x, y, z));
    mem(dist, -1);
    dist[x][y][z] = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = u.x, y = u.y, z = u.z;
        if(u==en) return dist[x][y][z];
        FOR(i, 6)
        {
            int a = x+fx[i], b = y+fy[i], c = z+fz[i];
            if(isvali(a, b, c) && grid[a][b][c]!='#' && dist[a][b][c]==-1){
                dist[a][b][c] = dist[x][y][z] + 1;
                Q.push(data(a, b, c));
            }
        }
    }
    return -1;
}

int main()
{
    int t, tst = 1;
    while(sf3(l, r, c))
    {
        if(l==0 && r==0 && c==0) return 0;
        data st, en;
        FOR(i, l)
        {
            FOR(j, r)
                sf("%s", grid[i][j]);
        }
        FOR(i, l)
        {
            FOR(j, r)
            {
                FOR(k, c)
                {
                    if(grid[i][j][k]=='S') st = data(i, j, k);
                    if(grid[i][j][k]=='E') en = data(i, j, k);
                }
            }
        }
        int ans = bfs(st, en);
        if(ans==-1) pf("Trapped!\n");
        else pf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}














