#include<stdio.h>
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int ara[100],n,i,j,k;

    while(1){
    scanf("%d",&n);
    if(n==0)break;
    for(i=0;i<100;i++)ara[i]=0;
    while(n--)
    {
        scanf("%d",&k);
        ara[k-1]++;
    }
for(i=0;i<100;i++)if(ara[i]!=0){printf("%d",i+1);ara[i]--; break;}
    for(i=0;i<100;i++)
    {
        if(ara[i]!=0)for(j=0;j<ara[i];j++)printf(" %d",i+1);
    }
    printf("\n");
    }
    return 0;
}
