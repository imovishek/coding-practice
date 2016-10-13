#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
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
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
int grid[8][8];
int Q[93][8][8];
int G[8][8];
int fx[] = {1,-1,-1,1};
int fy[] = {1,-1,1,-1};
bool isvali(int x, int y){return x>-1 && x<8 && y>-1 && y<8;}
bool check(int x, int y)
{
    if(grid[x][y]) return 0;
    for(int i = 0; i<8 ; i++)
        if(G[i][y] || G[x][i]) return 0;
    int a = x, b = y;
    FOR(i, 4)
    {
        a = x, b = y;
        while(isvali(a+fx[i], b+fy[i]))
        {
            a = a+fx[i];
            b = b+fy[i];
            if(G[a][b]==1) return 0;
        }
    }
    return 1;
}
int pos = 0;
void rec(int x)
{
    if(x==8){
        FOR(i, 8)
            FOR(j, 8)
            {
                Q[pos][i][j] = G[i][j];
            }
        pos++;
        return;
    }
    FOR(i,8)
    {
        if(check(x,i))
        {
            G[x][i] = 1;
            rec(x+1);
            G[x][i] = 0;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1, a;
    mem(Q, 0);
    rec(0);

    while(sf1(a)!=EOF)
    {
        mem(grid, 0);
        grid[0][a-1] = 1;
        for(int i = 1; i<8; i++){
            sf1(a);
            grid[i][a-1] = 1;
        }
        int maxi = 0;
        FOR(p, 92)
        {
            int cnt = 0;
            FOR(i, 8){
                FOR(j, 8)
                {
                    if(grid[i][j] && Q[p][i][j]) cnt++;
                }

            }
            maxi = max(cnt, maxi);
        }
        pcase(tst++);
        pf("%d\n",8-maxi);
    }
    return 0;
}

