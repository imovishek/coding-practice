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
int prime[10000];
int mark[10020];

void seive()
{
    for(int i = 3; i*i<10020; i+=2)
        if(mark[i]==0)
            for(int j = i*i; j<10020; j+=i+i)
                mark[j] = 1;
    int pos = 0;
    prime[pos++] = 2;
    for(int i = 3; i< 10020; i+=2)
        if(mark[i]==0) prime[pos++] = i;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n, x = 0;
    seive();
    while(sf1(n) && n)
    {
        x = 0;
        int sum =0, counti = 0;
        for(int i = 0; prime[i]<=n && prime[x]<=n; i++)
        {
            if(sum+prime[i]<=n){
                    if(sum+prime[i]==n){
                            counti++;
                    }
                    sum+=prime[i];
            }
            else if(sum+prime[i]>n){
                    sum-=prime[x++];
                    i--;
            }
        }
        pf("%d\n",counti);
    }
    return 0;
}


