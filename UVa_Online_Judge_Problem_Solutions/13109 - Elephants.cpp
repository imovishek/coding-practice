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
    sf1(t);
    while(t--)
    {
        int n , k;
        sf2(n ,k);
        int ara[n];
        FOR(i, n) sf1(ara[i]);
        sort(ara, ara+n);
        int counti = 0;
        FOR(i, n){
            k-=ara[i];
            if(k<0) break;
            counti++;
        }
        pf("%d\n",counti);

    }
    return 0;
}

