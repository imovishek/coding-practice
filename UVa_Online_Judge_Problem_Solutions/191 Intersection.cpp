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


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int x1, y1, x2, y2, ara[4][2];
    sf1(t);
    while(t--)
    {
        sf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &ara[0][0], &ara[0][1], &ara[1][0], &ara[1][1] );
         if(x1==x2 && y1==y2){
                if(y1<=ara[0][1] && x1<=ara[1][0] && x1>=ara[0][0] && y1>= ara[1][1])pf("T\n");
                else pf("F\n");continue;
        }
        ara[2][0] = ara[0][0];
        ara[2][1] = ara[1][1];
        ara[3][0] = ara[1][0];
        ara[3][1] = ara[0][1];

        int f = 0;
        int x=ara[0][0];
        int y=ara[0][1];
        int sig = (x-x1)*(y1-y2)-(y-y1)*(x1-x2);
//        pf("%d*\n", sig);
        int mx = max(x1, x2);
        int my = max(y1, y2);
        int nx = min(x1, x2);
        int ny = min(y1, y2);
        int mmx = max(ara[0][0], ara[1][0]);
        int mmy = max(ara[0][1], ara[1][1]);
        int nmx = min(ara[0][0], ara[1][0]);
        int nmy = min(ara[0][1], ara[1][1]);

        for(int i = 0; i<4 ; i++)
        {
            x=ara[i][0];
            y=ara[i][1];
            int val = ((x-x1)*(y1-y2)-(y-y1)*(x1-x2));
            if(sig * val<=0){
                if(mmx<nx || nmy>my || nmx>mx || mmy<ny)break;
                else{f=1; break;}
            }
            else if(val*sig==0){f = 1; break;}

        }
        if(f) pf("T\n");
        else pf("F\n");
    }
    return 0;
}

