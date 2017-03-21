#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
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
typedef double dbl;


int main()
{
    int t, tst = 1;
    sf1(t);
    char name[6][10]={"year", "month", "day", "hour", "minute", "second"};
    int ara[]={31104000,2592000,86400,3600,60, 1};
    int counti[6];
    while(t--)
    {
        int n;
        sf1(n);
        mem(counti, 0);
        FOR(i, 6)
        {
            counti[i] = n/ara[i];
            n%=ara[i];
        }
        int flag = 0;
        pcase(tst++);
        FOR(i, 6)
        {
            if(counti[i]!=0)
            {
                if(flag) pf(" ");
                flag = 1;
                pf("%d %s",counti[i],name[i]);
                if(counti[i]>1) pf("s");
            }
        }
        pf("\n");

    }
    return 0;
}

