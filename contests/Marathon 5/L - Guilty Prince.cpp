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

int n, m;

bool isvali(int x, int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
char grid[30][30];
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int cnt = 0;
int dfs(int x, int y)
{
    if(!isvali(x, y) || grid[x][y]=='#') return 0;
    grid[x][y] = '#';
    cnt++;
    FOR(i, 4)
        dfs(x+fx[i], y+fy[i]);
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf2(m,n);
        getchar();
        FOR(i, n)
            gets(grid[i]);
        FOR(i, n)
        {
            int f = 0;
            FOR(j, m)
            {
                if(grid[i][j]=='@') {
                    cnt = 0;
                    f = 1;
                    dfs(i, j);
                    break;
                }
            }
            if(f) break;
        }
        pcase(tst++);
        pf1(cnt);
    }
    return 0;
}














