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
    int dis;
    for(dis=0; dis+a<=n && a-dis>0 ;dis++)
    {
        if(ara[a+dis]==ara[a-dis] && ara[a+dis]==1)
        {
            if(dis!=0){
            counti+=2;
            }
            else counti++;
        }
    }
    if(a+dis>n){
        for(int i=a-dis;i>0;i--)
            if(ara[i]==1)counti++;
    }
    else if(a-dis<1){
        for(int i=a+dis;i<=n;i++)
            if(ara[i]==1)counti++;
    }
    printf("%d\n",counti);
    return 0;
}
