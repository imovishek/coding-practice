#include<bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<int ,pair<int,int> >
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
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
char grid[107][107];
bool flag[107][107];
int n, m;
bool isvali(int x, int y){return x>-1 && x<n && y>-1 && y<m;}

int cnt = 0;
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
void dfs(int x,int y, char ch)
{
    if(isvali(x, y) && grid[x][y]==ch && flag[x][y]==0){
        cnt++;
        flag[x][y] = 1;
    }
    else return;
    FOR(i, 4) dfs(x+fx[i], y+fy[i], ch);
}
struct data{
    char ch;
    int val;
};
bool comp(data a, data b)
{
    if(a.val==b.val)
        return a.ch<b.ch;
    return a.val>b.val;
}
int main()
{
    int t, tst = 1, pos = 0;
    data ara[10007];
    while(sf2(n,m))
    {
        if(n==0 && m==0) return 0;
        getchar();
        pos = 0;
        FOR(i, n) gets(grid[i]);
        FOR(i, n)
            FOR(j, m)
            {
                if(grid[i][j]!='.' && !flag[i][j])
                {
                    cnt = 0;
                    dfs(i, j, grid[i][j]);
                    ara[pos].val = cnt;
                    ara[pos++].ch = grid[i][j];
                }
            }
        sort(ara, ara+pos,comp);
        pf("Problem %d:\n",tst++);
        FOR(i, pos)
            pf("%c %d\n",ara[i].ch, ara[i].val);
        mem(flag, 0);

    }
    return 0;
}












