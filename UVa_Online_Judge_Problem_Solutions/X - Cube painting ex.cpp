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


int main()
{
    int t, tst = 1;
string line;
    while(getline(cin, line))
    {
        string x, y;
        FOR(i, 6) x+=line[i];
        FOR(i, 6) y+=line[i+6];
        vector<char>v1, v2;
        string format = "1342";
        FOR(i, 4) v1.pb(x[format[i]-'0']);
        FOR(i, 4) v2.pb(y[format[i]-'0']);
        char a = x[0], b = x[5];
        format = "";
        int f = 0;
        if(a!=y[0] || b!=y[5]) pf("FALSE\n");
        else{
            FOR(i, 4)
            {
                if(v1==v2) {f = 1; break;}
                char x = v2[3];
                v2.ppb;
                v2.insert(v2.begin(), x);
            }
            if(f) pf("TRUE\n");
            else pf("FALSE\n");
        }

    }
    return 0;
}














