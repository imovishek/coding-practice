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
char grid[37][107];
int n;
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
void dfs(int x, int y, char con, char mark)
{
    FOR(i, 4){
        int a = x+fx[i];
        int b = y+fy[i];
        if(grid[a][b]==' '){
            grid[a][b] = mark;
            dfs(a, b, con, mark);
        }
    }

}
int main()
{
    while(gets(grid[0]))
    {
        if(grid[0][0]==0)    // newline
        {
            puts("");
            gets(grid[0]);      // abar nibe
        }
        n = 1;
        while(gets(grid[n]) && grid[n++][0]!='_');
        n--;
        char contour;
        for(int i = 0; grid[0][i] ; i++) if(grid[0][i]!=' ') contour = grid[0][i];
//        pf("%c\n",contour);
        FOR(i, n)
        {
            for(int j = 0; grid[i][j] ; j++)
                if(grid[i][j]!=' ' && grid[i][j]!=contour){
//                    pf("%d %d %c+++\n",i,j,grid[i][j]);
                    dfs(i, j, contour, grid[i][j]);
                }

        }
        FOR(i, n+1) puts(grid[i]);
    }
    return 0;
}
/*

XXXXXXXXXXXXXXXXXXXX
X       X          X
X # # XXXXXXXX /   X
X            X     X
XXXXXXXXXXXXXXXXXXXX
_____________________________

 AAAAAAAAAAA
 A       A  AAAAA
  A  8  A A  *  A
   A   A   A  *A
    A A     AAA
     A
_____________________________
*/









