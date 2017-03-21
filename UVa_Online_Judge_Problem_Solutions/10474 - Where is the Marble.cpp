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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n, q;
    while(sf2(n, q)!=EOF)
    {
        if(n==0 && q==0) return 0;
        int ara[n];
        FOR(i, n) sf1(ara[i]);
        pf("CASE# %d:\n",tst++);
        sort(ara, ara+n);
        int f[10007];
        mem(f, 0);
        FOR(i, n){
            if(!f[ara[i]]) f[ara[i]] = i+1;
        }
        FOR(i, q)
        {
            int a;
            sf1(a);
            if(!f[a]) pf("%d not found\n", a);
            else pf("%d found at %d\n", a, f[a]);
        }
    }
    return 0;
}








