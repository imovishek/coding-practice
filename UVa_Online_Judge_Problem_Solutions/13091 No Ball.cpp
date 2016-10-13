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

int main()
{
    char grid[10][10];
    int t,tst = 1;
    sf1(t);
    while(t--)
    {
        getchar();
        FOR(i, 5) gets(grid[i]);
        pcase(tst++);
        FOR(i, 5)
        {
            FOR(j, 5)
            {
                if(grid[i][j]=='>')
                {
                    int flag = 0;
                    for(int k = j; k<5; k++)
                    if(grid[i][k]=='|'){
                        flag = 1;
                        pf("Thik Ball\n");
                    }
                    if(!flag) pf("No Ball\n");
                }
                else if(grid[i][j]=='<')
                {
                    int flag = 0;
                    for(int k = j; k<5; k++)
                    if(grid[i][k]=='|'){
                        flag = 1;
                        pf("No Ball\n");
                    }
                    if(!flag) pf("Thik Ball\n");
                }
            }
        }
    }
    return 0;
}
