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
#define pf printf
#define sf scanf
#define pcase(x) printf("Case %d: ",x)
using namespace std;
typedef unsigned long long int ulint;
typedef long long int lint;
typedef double dbl;
ulint ara[100000];
ulint get(lint n)
{
    if(n==1)return 1;
    if(n<100000 && ara[n]!=0)return ara[n];
    ulint hl=get(n/2);
    if(n<100000 && n&1){
        ara[n]=(hl*get(n/2+1)+2);
    }
    else if(n<100000) {
            ara[n]=(hl*hl+1);
    }
    else if(n&1)
    {
        return (hl*get(n/2+1)+2);
    }
    else return (hl*hl+1);

    return ara[n];

}
int main()
{
//    printf("%I64u\n",get(1000));
    ara[1]=1;
    int t,tst=1;
    lint n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
            pcase(tst++);

            printf("%llu\n",get(n));

    }
    return 0;
}
