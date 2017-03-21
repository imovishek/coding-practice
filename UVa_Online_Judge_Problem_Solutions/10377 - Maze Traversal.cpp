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
int fx[]= {0,1,0,-1};
int fy[]= {1,0,-1,0};
int n, m;
bool isvali(int x, int y){ return x>0 && y>0 && x<=n && y<=m;}
char grid[125][125];
int main()
{
    int x, y, t;
    sf1(t);
    while(t--)
    {
        char d;
        int dik=3;
        sf2(n,m);
        getchar();
        FOR(i, n) gets(grid[i]);
        sf2(x, y);
        char s;
        while(sf(" %c",&s) && s!='Q')
        {
            if(s=='R') dik = (dik+1)%4;
            else if(s=='L') dik = (dik+3)%4;
            else if(s=='F'){
                if(isvali(x+fx[dik], y+fy[dik]) && grid[x+fx[dik]-1][y+fy[dik]-1]!='*')
                {
                    x+=fx[dik];
                    y+=fy[dik];
                }
            }
        }
        switch(dik)
        {
        case 0:
            d = 'E';
            break;
        case 1:
            d = 'S';
            break;
        case 2:
            d = 'W';
            break;
        case 3:
            d = 'N';
            break;
        }
        pf("%d %d %c",x,y,d);
        pf("\n");
        if(t) pf("\n");
    }
    return 0;
}
/*
1

7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ
*/
