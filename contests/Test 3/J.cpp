#include<bits/stdc++.h>
#define pii pair<int,int>
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
vector<int> vt;
char ara[8][10];
int n , k;
int ans = inf;
bool flag[10];
void rec()
{
    if(vt.size()==k){
        int mini = inf, maxi = 0;
        FOR(i, n){
            int num = 0;
            FOR(j, k){
                num*=10;
                num+=ara[i][vt[j]] - '0';
            }
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        ans = min(ans, maxi-mini);
        return;
    }
    FOR(i, k)
    {
        if(!flag[i]){
            flag[i] = 1;
            vt.pb(i);
            rec();
            vt.ppb;
            flag[i] = 0;
        }
    }
}

int main()
{
    int t, tst = 1;
    sf2(n, k);
    getchar();
    FOR(i, n)
    {
        gets(ara[i]);
    }
    rec();
    pf1(ans);
    return 0;
}














