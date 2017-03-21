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

int T[1007], n;
int ara[1007][11];
int lcm()
{
    lint l = 1;
    FOR(i, n) {
        if(ara[i][0]==-1) continue;
        l = l/__gcd((int)l, T[i])*T[i];
    }
    return int(l);
}
int main()
{
    int t, tst = 1;
    sf1(t);
    while(t--){
        sf1(n);
        FOR(i, n){
            sf1(T[i]);
            FOR(j, T[i])
            {
                sf1(ara[i][j]);
            }
        }
        int l = lcm();
        int x = 0 , ans = n;
        int loop = 0;
        while(1){
            int flag = 0;
            int l = lcm();
            for(int d = loop ; d< loop+l ; d++)
            {
                int mini = inf, pos;
                FOR(i, n)
                {
                    if(ara[i][0]==-1)continue;
                    if(mini > ara[i][d%T[i]])
                    {
                        mini = ara[i][d%T[i]];
                        pos = i;
                    }
                }
                int f = 0;
                FOR(i, n)
                {
                    if(ara[i][0]==-1)continue;
                    if(ara[i][d%T[i]]==mini)f++;
                }

                if(f==1) {
                        ara[pos][0] = -1;
                        x = d+1;
                        ans--;
                        flag = 1;
                }
            }
            if(!flag) break;
            loop+=l;
        }
        pf("%d %d\n", ans, x);
    }
    return 0;
}














