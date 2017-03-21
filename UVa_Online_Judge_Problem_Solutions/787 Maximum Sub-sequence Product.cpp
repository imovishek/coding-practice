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
    int a;
    while(sf1(a)!=EOF)
    {
        vector<int>vt;
        vt.pb(a);
        while(sf1(a) && a!=-999999)
            vt.pb(a);
        lint x, y, neg = 0, flag = 0, maxi = -inf;
        FOR(i, vt.size())
        {
            if(vt[i]<0) neg++;
            if(vt[i]==0) x = i+1;
        }
        if(ln!=-1 && ln!=vt.size()-1)  maxi = max(maxi, ans/vt[ln]);
        pf("%lld\n", maxi);

    }
}
