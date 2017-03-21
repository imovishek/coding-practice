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
int ara[125];
int dp[107][50007];
int mini = inf, m, avg, sum;
int rec(int pos, int wt)
{
    mini = min(mini, abs(2*wt - sum));
    if(pos==m || wt>avg) return 1;
    if(dp[pos][wt]!=-1) return 1;
    rec(pos+1, wt);
    rec(pos+1, wt+ara[pos]);
    dp[pos][wt] = 1;
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf1(m);
        sum = 0;
        if(m==0){
            pf("0\n");
            continue;
        }
        FOR(i, m){sf1(ara[i]); sum+=ara[i];}
        avg = sum/2;
        FOR(i, m) FOR(j, sum+1) dp[i][j] = -1;
        mini = inf;
        rec(0,0);
        pf("%d\n",mini);

    }
    return 0;
}

