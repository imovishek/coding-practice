#include<bits/stdc++.h>
#define pii pair<int,int>
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
#define MX 1000005
#define inf 2147483647
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;

int n, m;
char grid[57][57];
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
bool isvali(int x, int y){ return x>-1 && y>-1 && x<n && y<m;}
void dfs2(int x, int y)
{
    if(!isvali(x, y) || grid[x][y]!='X') return;
    grid[x][y] = '.';
    FOR(i, 4)
        dfs2(x+fx[i], y+fy[i]);

}
int cnt = 0;
void dfs(int x, int y)
{
    if(!isvali(x, y) || grid[x][y]=='.') return;
    if(grid[x][y]=='X'){ dfs2(x,y); cnt++;}
    grid[x][y] = '.';
    FOR(i, 4)
        dfs(x+fx[i], y+fy[i]);
}
int main()
{
    int tst = 1;
    while(sf2(m , n))
    {
        if(n==0 && m==0) return 0;
        getchar();
        priority_queue<int, vector<int>, greater<int> >pQ;
        FOR(i, n) gets(grid[i]);
        FOR(i, n)
            FOR(j, m)
            {
                cnt = 0;
                dfs(i,j);
                if(cnt) pQ.push(cnt);
            }
        pf("Throw %d\n%d",tst++,pQ.top());
        pQ.pop();
        while(!pQ.empty())
        {
            pf(" %d",pQ.top());
            pQ.pop();
        }
        pf("\n\n");

    }
    return 0;
}
/*
30 15
..............................
..............................
..............*...............
............****......*****...
...........***X***.....**X*...
............**X***....*****...
.............****.....*X***...
..............*.......*****...
..............................
.....******........***........
.....*X****.....*X**X**.......
.....******......*******......
.....*X**.......*X**X****.....
.....******........***........
..............................
*/

