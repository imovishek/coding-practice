#include<bits/stdc++.h>
#define pii pair<int,int>
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

int main()
{
//    freopen("ot.txt","r",stdin);
//    freopen("tput.txt","w",stdout);
    int n;
    while(sf1(n) && n)
    {
        int a;
        priority_queue< lint , vector<lint>, greater<lint> > pQ;
        FOR(i, n){ sf1(a); pQ.push(a);}
        lint sum = 0;
        while(pQ.size()!=1)
        {
            lint x = pQ.top();
            pQ.pop();
            lint y = pQ.top();
            pQ.pop();
            pQ.push(x+y);
            sum+=x+y;
        }
        pf("%lld\n",sum);

    }
    return 0;
}
