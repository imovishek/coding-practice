#include<bits/stdc++.h>
#define pii pair<int,int>
#define mkp make_pair
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
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;


int main()
{
    int t, tst = 1;
    int n;
    sf1(n);
    char ara[n][n+5];
    FOR(i, n) sf("%s", ara[i]);
    lint ans = 0;
    FOR(i, n)
    {
        lint cnt = 0;
        FOR(j, n) if(ara[i][j]=='C')cnt++;
        ans+=cnt*(cnt-1)/2;
    }
    FOR(i, n)
    {
        lint cnt = 0;
        FOR(j, n) if(ara[j][i]=='C')cnt++;
        ans+=cnt*(cnt-1)/2;
    }
    pf("%I64d\n", ans);
    return 0;
}

