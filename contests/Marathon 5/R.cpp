#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
char grid[100][10000];
char flag[100][10000];
char flagi[100][10000];
int n, m;
bool isvali(int x, int y)
{
    return x>-1 && y>-1 && x<100 && y<100;
}
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
void dfs(int x, int y)
{
    grid[x][y] = ' ';
    FOR(i, 4)
    {
        int a = fx[i] + x;
        int b = fy[i] + y;
        if(isvali(a, b))
        {
            if(isalpha(grid[a][b])) grid[x][y] = '#';
            if((grid[a][b]==' ' || grid[a][b]==0) && flag[a][b]==0){
                flag[a][b] = 1;
                dfs(a, b);
            }
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    getchar();
    while(gets(grid[0]))
    {
        char ara[10000];
        strcpy(ara, grid[0]);
        int la[10000];
        mem(grid, 0);
        strcpy(grid[0], ara);
        int pos = 1;
        n = 1;
        la[0] = m = strlen(grid[0]);
        while(gets(grid[pos++])) {
            n++;
            int len = strlen(grid[pos-1]);
            la[pos-1] = len;
            m = max(m, len);
            if(grid[pos-1][0]=='_'){
                n--;
                break;
            }
        }

        mem(flag, 0);
        mem(flagi, 0);
        FOR(i, n)
        {
            FOR(j, m)
            {
                if(grid[i][j]=='*'){
                    flagi[i][j] = 1;
                    dfs(i, j);
                }
            }
        }
        FOR(i, n+1){
            int f = 1;
            FOR(j, 100)
            {
                int a = 100-j-1;
                if(flagi[i][a] || (grid[i][a]!=' ' && grid[i][a]!=0)){
                    if(flagi[i][a]) f = 0;
                    break;
                }
            }
            FOR(j, 100)
            {
                int a = 100-j-1;
//                if(f && la[i]>a) break;
                if(grid[i][a]!=' ' && grid[i][a]!=0) break;
                grid[i][a] = 0;
            }
        }
        FOR(i, n+1) puts(grid[i]);

    }
    return 0;
}













