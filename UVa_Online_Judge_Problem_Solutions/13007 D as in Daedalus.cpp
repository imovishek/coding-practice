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
    int t, tst = 1;
    int n, m;
    while(sf2(n, m)!=EOF)
    {
        int ans = 0;
        FOR(i, m){
            int sum = 0, budget, first;
            sf1(budget);
            sf1(first);
            FOR(i, n-1)
            {
                int a;
                sf1(a);
                sum+=a;
            }
            if(sum+first<=budget){
                int diff = budget - sum;
                if(diff>=10000) ans+=10000;
                else if(diff>=1000) ans+=1000;
                else if(diff>=100) ans+=100;
                else if(diff>=10) ans+=10;
                else if(diff>=1) ans+=1;
                ans-=first;
            }
            else if(sum+10000<=budget)
                ans+=10000;
            else if(sum+1000<=budget)
                ans+=1000;
            else if(sum+100<=budget)
                ans+=100;
            else if(sum+10<=budget)
                ans+=10;
            else if(sum+1<=budget)
                ans+=1;

        }
        pf1(ans)
    }
    return 0;
}




