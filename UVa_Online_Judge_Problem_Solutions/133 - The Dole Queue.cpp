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
#include<list>
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
#define MX 1000000007
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
//#define seti(p,x) p|=(1<<x)
//#define check(p,x) (p & (1<<x))
//#define reseti(p,x) p&=(~(1<<x))

////8 moves
//int fx[]={1,1,1,0,0,-1,-1,-1};
//int fy[]={1,0,-1,1,-1,1,0,-1};
//
////4 moves
//int fx[]= {1,0,0,-1};
//int fy[]= {0,1,-1,0};
//
////night moves
//int fx[]={2,2,-2,-2,1,-1,1,-1};
//int fy[]={1,-1,1,-1,2,2,-2,-2};

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n,k,m;
    while(sf3(n,k,m))
    {
        if(!k&&!m&&!n) break;
        list<int> lst;
        list<int>::iterator it, x, y;
        FOR(i,n) lst.pb(i+1);
        x = lst.begin();
        y = lst.end();
        y--;
        int flag = 0, f = 0;
        int tm = m, tn = n;
        while(!lst.empty())
        {
            it = x;
            pf("\n");
            FOR(i, k-1)
            {
                if(it==lst.end()) it = lst.begin();
                it++;
                pf("%d**\n", *it);
            }
            x = it;
            it = y;
            pf("--------------\n");
            FOR(i,m-1)
            {
                if(it==lst.begin()) it = lst.end();
                it--;
                pf("%d**\n", *it);
            }
            y = it;
            int a = *x, b = *y;
            pf("\n%d %d**\n",a,b);
            while(1){
                x++;
                if(x==lst.end()) x = lst.begin();
                if(x!=y) break;
                if(*x==a) break;
            }
            while(1){
                if(y==lst.begin()) y = lst. end();
                y--;
                if(*y!=a) break;
                if(*y==b)break;
            }
            pf("\n%d %d** imp\n",*x,*y);
            if(a==b){
                if(flag) pf(",");
                pf("%3d",a);
                flag = 1;
                lst.remove(a);
                for(it = lst.begin(); it!=lst.end(); it++)
                    pf(" %d *",*it);
                pf("\n");
            }
            else{
                if(flag) pf(",");
                pf("%3d%3d",a,b);
                flag = 1;
                lst.remove(a);
                lst.remove(b);
                for(it = lst.begin(); it!=lst.end(); it++)
                    pf(" %d ",*it);
                pf("\n");
            }


        }
        pf("\n");
    }
    return 0;
}

