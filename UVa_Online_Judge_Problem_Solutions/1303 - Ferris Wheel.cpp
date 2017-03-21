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
    sf1(t);
    while(t--)
    {
        int n, m;
        sf2(n,m);
        list<int>lst;
        list<int>:: iterator it;
        int ara[m];
        int flag[n][m];
        mem(flag, 0);
        mem(ara, -1);
        FOR(i, n) lst.pb(i);
        int ans = 0, sig=0;
        FOR(i , m)
        {
            if(ara[i]!=-1) lst.pb(ara[i]);
            if(!lst.empty()){
                int f = 0;
                for(it=lst.begin(); it!=lst.end() ;it++){
                    if(flag[*it][i]==0){
                        f = 1;
                        flag[*it][i]=1;
                        sig++;
                        ara[i] = *it;
                        lst.remove(*it);
                        break;
                    }
                }
                if(!f)ara[i] = -1;
            }
            ans+=5;
            if(sig==n*m){
                    ans+=m*5;
                    break;
            }
            if(i==m-1) i = -1;
        }
        pcase(tst++);
        pf("%d\n",ans);
    }
    return 0;
}

