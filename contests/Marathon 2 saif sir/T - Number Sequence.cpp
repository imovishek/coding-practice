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
#define sf1ll(a) scanf("%lld",&a)
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
int mx = 32800;
int ara[32800];
int digit(int n)
{
    int cnt = 0;
    while(n)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
int main()
{
    int t, tst = 1;
    sf1(t);
    ara[1] = 1;
    for(int i = 2; i<mx ; i++)
        ara[i] = ara[i-1] + digit(i);
    while(t--)
    {
        lint n;
        sf1ll(n);
        lint sum = 0, i, ans;
        for(i = 1; sum+ara[i]<=n ; i++)
            sum+=ara[i];
        if(n-sum){
            lint x = n-sum;
            int j;
            for(j = 1; ara[j]<=x; j++);
            x-=ara[j-1];
            if(!x) ans = (j-1)%10;
            else{
                char str[10];
                sprintf(str, "%d", j);
                ans = str[x-1]-'0';
            }
        }
        else ans = (i-1)%10;
        pf("%lld\n", ans);

    }
    return 0;
}













