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
#define pcase(x) printf("Case %d:\n",x)
#define MX 1000000007
#define inf 2147483647
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)
using namespace std;
typedef long long int lint;
typedef double dbl;
int mark[33]= {0, 0 , 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};
int n;
int flag[17];
vector<int>vt;
void backtrack(int now)
{
    if(vt.size()==n){
        if(!mark[now+1])return;
        for(int i = 0; i<n ; i++)
            pf("%d%c",vt[i]," \n"[i==n-1]);
    }
    for(int i = 2; i<=n ; i++){
        if(flag[i]==0 && mark[i+now])
        {
            flag[i] = 1;
            vt.pb(i);
            backtrack(i);
            vt.ppb;
            flag[i] = 0;
        }
    }
}
int main()
{
    int tst = 1;
    while(sf1(n)!=EOF)
    {
        if(tst!=1)pf("\n");
        flag[1] = 1;
        vt.pb(1);
        pcase(tst++);
        backtrack(1);
        vt.ppb;
    }
    return 0;
}

