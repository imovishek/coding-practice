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
int flag[1000007];

int main()
{
    int t, tst = 1;
    pair<int , string> ara[3007];
    int n;
    sf1(n);
    FOR(i, n)
        cin >> ara[i].sc >> ara[i].fs;
    sort(ara, ara+n);
    int ans[n];
    int f = 0, curr = 10000007, prev = -1;

    FOR(i, n)
    {
        int a = n-i-1;
        int actcnt = ara[a].fs, cnt=0;
        if(actcnt>a) {f=1; break;}
        for(int j = n; j>=1; j--){
            if(!flag[j]) {
                if(cnt==actcnt){
                    flag[j] = 1;
                    ans[a] = j;
                    cnt++;
                    break;
                }
                cnt++;
            }

        }
    }
    if(f) pf("-1\n");
    else FOR(i, n) pf("%s %d\n", ara[i].sc.c_str(), ans[i]);
    return 0;
}














