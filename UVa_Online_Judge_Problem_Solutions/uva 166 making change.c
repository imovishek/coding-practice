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
#define pi acos(-1.0)
using namespace std;
typedef long long int lint;
typedef double dbl;
int coin[]={5, 10, 20, 50, 100, 200};
int c[7];
int tabledp(int m)
{
    int ara[m+2];
    memset(ara,0,sizeof(ara));
    for(int i=0;i<6;i++)
    {
        for(int j=m;j>=coin[i];j++)
        {
            ara[j]=min(ara[j-coin[i]+1,ara[j]);
        }
    }
    return ara[m];
}
int main()
{
    int m,n;
    while(1)
    {
        int zeros=0;
        for(int i=0;i<6;i++){
            sf1(c[i]);
            if(c[i]==0)zero++;
        }
        if(zero==6)break;

        sf("%d.%d",&m,&n);
        m=(m*100+n);
        pf("minimum coin: to make %d.%d is %d\n",m/100,n, tabledp(m));


    }
    return 0;
}
