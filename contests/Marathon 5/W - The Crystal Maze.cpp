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
#define pcase(x)        printf("Case %d:\n",x)
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

int n, m;

bool isvali(int x, int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
char grid[507][507];
int ans[507][507];
int flag[507][507];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int cnt = 0;
int dfs(int x, int y)
{
    if(!isvali(x, y) || grid[x][y]=='#' || flag[x][y]) return 0;
    if(grid[x][y]=='C') cnt++;
    flag[x][y] = 1;
    FOR(i, 4)
        dfs(x+fx[i], y+fy[i]);
    ans[x][y] = cnt;
}

int dfs2(int x, int y, int col = 0)
{
    if(!isvali(x, y) || grid[x][y]=='#') return 0;
    grid[x][y] = '#';
    FOR(i, 4)
        dfs2(x+fx[i], y+fy[i], col);
    ans[x][y] = col;
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        int q;
        sf2(n, m);
        sf1(q);
        getchar();
        FOR(i, n)
            gets(grid[i]);
        mem(ans, 0);
        mem(flag, 0);
        FOR(i, n)
        {
            int f = 0;
            FOR(j, m)
            {
                if(grid[i][j]!='#') {
                    cnt = 0;
                    dfs(i, j);
                    dfs2(i, j, cnt);
                }
            }
        }
//        FOR(i, n){
//        FOR(j, m)
//            pf("%d ", ans[i][j]);
//            pf("\n");
//        }

        pcase(tst++);
        FOR(i, q)
        {
            int x, y;
            sf2(x, y);
            pf1(ans[x-1][y-1]);
        }
    }
    return 0;
}














