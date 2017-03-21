#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef long long int lint;
typedef double dbl;
int main()
{
    int n;
    int t;
    sf1(t);
    while(t--)
    {
        sf1(n);
        int ara[n];
        for(int i=0;i<n;i++)
            sf1(ara[i]);
        int counti=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ara[i]*2==ara[j])counti ++;
        pf("%d\n",counti);
    }
    return 0;
}
