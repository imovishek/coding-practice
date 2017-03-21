#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i,j,
    ara[4][2]={
        300000,10,
        400000,15,
        300000,20,
        2147483647,25};
    long long int  res,n;

    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        res=0;

        n-=180000;
        for(j=0;j<4;j++)
        {
            if(n>0 && n<ara[j][0]){
                res+=n*ara[j][1];
                n-=ara[j][0];
            }
            else if(n>=ara[j][0]){
                res+=ara[j][0]*ara[j][1];
                n-=ara[j][0];
            }

        }
        if(res%100!=0){res=(res+99)/100;}
        else res/=100;
        if(res>0 && res<2000)res=2000;
        printf("Case %d: %lld\n",i,res);

    }

    return 0;
}
