#include<bits/stdc++.h>
#define pii pair<int,lint>
#define mkp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define pf1(a) printf("%d\n",a)
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sf1ll(a) scanf("%lld",&a)
#define sf2ll(a,b) scanf("%lld %lld",&a,&b)
#define sf3ll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define MX 1000000007
#define inf 1000000007
#define pi acos(-1.0)
#define mem(arr,x) memset((arr), (x), sizeof((arr)));
#define FOR(i,x) for(int i=0;i<(x); i++)

using namespace std;
typedef long long int lint;
typedef double dbl;
char A[31];
char B[31];
pii dp[30][30];
pii rec(int i, int j)
{
    if(i==-1) return pii(j+1, 1);
    if(j==-1) return pii(i+1, 1);
    pii &ret = dp[i][j];
    if(ret.fs!=-1) return ret;
    if(A[i]==B[j]) {
            pii now = rec(i-1, j-1);
            ret.fs = now.fs + 1;
            ret.sc = now.sc;
    }
    else {
            pii now1 = rec(i-1, j), now2 = rec(i, j-1);
            if(now1.fs==now2.fs){
                ret.fs = now1.fs + 1;
                ret.sc = now1.sc + now2.sc;
            }
            else{
                if(now1.fs>now2.fs){
                    ret.fs = now2.fs + 1;
                    ret.sc = now2.sc;
                }
                else{
                    ret.fs = now1.fs + 1;
                    ret.sc = now1.sc;
                }
            }
    }
    return ret;
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--)
    {
        sf("%s %s", A, B);
        int l1 = strlen(A), l2 = strlen(B);
        FOR(i, l1)
            FOR(j, l2)
                dp[i][j].fs = -1;
        pii ans = rec(l1-1, l2-1);
        pcase(tst++);
        pf("%d %lld\n", ans.fs, ans.sc);
    }

    return 0;
}




/*

ABCBDAB
BDCABC

*/









