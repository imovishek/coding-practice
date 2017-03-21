#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define pf printf
#define sf scanf
using namespace std;
typedef long long int lint;
typedef double dbl;

lint H(lint n)
{
    lint res = 0,last=0,now;
    for(lint i = 1; i <= n; i++ )
    {
        now=n/i;
        if(last==now)
        {
            lint num=n/now-n/(now+1)-1;
            res+=(num)*now;
            i+=num-1;
        }
        else res+=now;
        last=now;
    }
    return res;
}


int main()
{
    lint t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",H(n));
    }
    return 0;
}
