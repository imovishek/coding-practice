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

int tim = 21;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, tst = 1;
    int n;
    while(sf1(n)!=EOF)
    {
        int a, b, c, d, e, f, m, k;
        sf("%d:%d:%d,%d --> %d:%d:%d,%d\n", &a, &b, &c, &m, &d, &e, &f, &k);
        string ara[100];
        int pos = 0;
        while(getline(cin, ara[pos]) && ara[pos++].length());
        c-=tim;
        if(c<0) {
            c+=60;
            b--;
            if(b<0){
                a--;
                b+=60;
            }
        }

        f-=tim;
        if(f<0) {
            f+=60;
            e--;
            if(e<0){
                d--;
                e+=60;
            }
        }
        if(tst++>1)pf("\n");
        pf1(n);
        pf("%02d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d\n", a, b, c, m, d, e, f, k);
        FOR(i, pos)
            pf("%s\n", ara[i].c_str());
    }
    return 0;
}














