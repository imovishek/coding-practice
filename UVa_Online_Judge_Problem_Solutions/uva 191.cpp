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
#define hihi printf("hi hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int x1,y1,x2,y2,ara[4][2],x,y;
    int t;
    sf1(t);
    while(t--)
    {
        sf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&ara[0][0],&ara[0][1],&ara[1][0],&ara[1][1]);
        if(x1==x2 && y1==y2){
                if(y1<=ara[0][1] && x1<=ara[1][0] && x1>=ara[0][0] && y1>= ara[1][1])pf("T\n");
                else pf("F\n");continue;
        }
        ara[2][0]=ara[0][0];
        ara[2][1]=ara[1][1];
        ara[3][0]=ara[1][0];
        ara[3][1]=ara[0][1];
        int flag=0;
        x=ara[0][0];
        y=ara[0][1];
        int diffx=(x1-x2),diffy=(y1-y2);
        int c=y1*diffx-x1*diffy,det;
        det=x*diffy-y*diffx+c;
        if(det==0){pf("T\n");continue;}
        if(det>0)flag=1;
        for(int i=1;i<4;i++)
        {
            x=ara[i][0];
            y=ara[i][1];
            det=x*diffy-y*diffx+c;
            if(flag)
            {
//                hi
                if(det<=0){flag=5;break;}

            }
            else {
//                    hihi
                if(det>=0){flag=5;break;}

            }

        }
        if(flag==5)pf("T\n");
        else pf("F\n");

    }
    return 0;
}
/*
10
8 0 0 8 2 2 9 9
8 0 0 8 9 9 2 2
0 8 8 0 2 2 9 9
0 8 8 0 9 9 2 2
8 0 0 8 100 100 10 6
2 2 3 3 -6 -1 5 1
16 0 0 16 10 6 100 100

*/
