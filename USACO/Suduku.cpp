#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d:\n",x)
#define pi acos(-1.0)
#define FOR(i,x) for(int i=0;i<(x);i++)
#define seti(x,y) x|=(1<<y)
#define checki(x,y) (bool)(x&(1<<y))
using namespace std;
typedef long long int lint;
typedef double dbl;
int flag[9][9];
int det=0;//56
void p2d(int allb[][9])
{
    FOR(i,9){
                pf("%d",allb[i][0]);
                FOR(j,8){
                    printf(" %d", allb[i][j+1]);
                }
                pf("\n");
            }
}
bool check(int val, int x, int y)
{
    FOR(i,9)
    {
        if(flag[x][i]==val)return 0;
    }
    FOR(i,9)
    {
        if(flag[i][y]==val)return 0;
    }
    for(int i=(x/3)*3,k=0;k<3;k++,i++)
        for(int j=(y/3)*3,l=0;l<3;l++,j++)
        {
            if(flag[i][j]==val)return 0;
        }
    return 1;
}
void setval(int val, int x, int y, int allb[][9], int chances[][9])
{
    flag[x][y]=val;
    FOR(i,9)
    {
        if(flag[x][i]!=0)continue;
        if(!checki(allb[x][i], val))chances[x][i]++;
        seti(allb[x][i], val);
    }
    FOR(i,9)
    {
        if(flag[i][y]!=0)continue;
        if(!checki(allb[i][y], val))chances[i][y]++;
        seti(allb[i][y], val);
    }

    for(int i=(x/3)*3,k=0;k<3;k++,i++)
        for(int j=(y/3)*3,l=0;l<3;l++,j++)
        {
            if(flag[i][j]!=0)continue;
            if(!checki(allb[i][j], val))chances[i][j]++;
            seti(allb[i][j], val);
        }

}

pii sorta(int chances[][9])
{
    int maxi=0, x, y;
    FOR(i,9)
        FOR(j,9)
        {
            if(maxi < chances[i][j] && !flag[i][j]){
                maxi=chances[i][j];
                x=i;y=j;
            }

        }
    return pii(x,y);
}
bool checkall()
{
    FOR(i,9)
        FOR(j,9)
        {
            if(flag[i][j]==0)return 0;
        }
    return 1;
}
int bigflag=0;
void solveit(int chan[][9], int alu[][9])
{
    if(det==81){
//            pf("kida?\n");
            bigflag=1;
            return;
    }
    pii cordi=sorta(chan);
//    pf("%d %d %d*\n",cordi.fs, cordi.sc, flag[cordi.fs][cordi.sc]);
    int chances[9][9], allb[9][9];
    for(int i=1;i<10;i++)
    {
        if(checki(alu[cordi.fs][cordi.sc], i)==0){
        FOR(j,9)
            FOR(k,9)
            {
                chances[k][j]=chan[k][j];
                allb[k][j]=alu[k][j];
            }
        if(check(i, cordi.fs, cordi.sc)==0)continue;
        det++;
        setval(i, cordi.fs, cordi.sc, allb, chances);
        solveit(chances, allb);
        det--;
        if(bigflag==0)
            flag[cordi.fs][cordi.sc]=0;
        }

    }
}
int main()
{
    int t,tst=1;
    int chances[9][9], allb[9][9];
    char ch;
    sf("%d",&t);
    while(t--)
    {
        FOR(i,9)
            FOR(j,9){
            chances[i][j]=0;
            allb[i][j]=0;
            flag[i][j]=0;
            }
        FOR(i,9)
            FOR(j,9){
                sf(" %c",&ch);
                if(ch=='.')flag[i][j]=0;
                else {
                        setval(ch-'0', i, j, allb, chances);
                        flag[i][j]=ch-'0';
                        det++;
                }
            }
            solveit(chances, allb);
//            p2d(allb);
            pcase(tst++);
            FOR(i,9){
                pf("%d",flag[i][0]);
                FOR(j,8){
                    printf(" %d", flag[i][j+1]);
                }
                pf("\n");
            }
            bigflag=0;
            det=0;
    }
    return 0;
}
/*
2

.46...9..
.3.1.....
.2..6..85
...87....
6...3...4
....14...
79..5..3.
.....2.4.
..2...61.

.....5.8.
...6.1.43
.........
.1.5.....
...1.6...
3.......5
53.....61
........4
.........


.7...6...
9......41
..8..9.5.
.9...7..2
..3...8..
4..8...1.
.8.3..9..
16......7
...5...8.

*/

