#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n,a,counti=0;
    scanf("%d %d",&n,&a);
    int ara[n+1];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ara[i]);
    }
    for(int dis=0;(dis+a>0 && dis+a<=n)&&(-dis+a>0 && -dis+a<=n);dis++)
    {
        if(ara[a+dis]==ara[a-dis] && ara[a+dis]==1)
            counti++;
    }
    if(a+dis>n){
        for(int i=a-dis-1;i>0;i--)
            if(ara[i]==1)counti++;
    }
    if(a-dis<1){
        for(int i=a+dis+1;i<=n;i++)
            if(ara[i]==1)counti++;
    }

    return 0;
}
