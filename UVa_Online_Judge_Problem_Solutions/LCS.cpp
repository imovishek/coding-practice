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

char a[]="MZJAWXU";
char b[]="XMJYAUZ";
int dp[7][7];
int rec(int x, int y)
{
    if(x==7 || y==7) return 0;
    if(dp[x][y]) return dp[x][y];
    if(a[x]==b[y]) return dp[x][y]=1 + rec(x+1, y+1);
    return dp[x][y] = max(rec(x+1, y), rec(x, y+1));
}
int main()
{
    int t, tst = 1;
    pf("%d\n", rec(0, 0));
    return 0;
}

