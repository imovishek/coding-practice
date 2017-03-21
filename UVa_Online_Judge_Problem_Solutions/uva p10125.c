#include<stdio.h>
int main()
{
    int i,j,k,max=0,n;

    while(1)
    {

        scanf("%d",&n);
        if(n==0)break;
        long long ara[n],ara2[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
        {


            if(ara[j]>max){max=ara[j];k=j;}
        }
        ara2[i]=max;
        printf("%d ",max);
max=0;
        ara[k]=0;
        }

    }

    return 0;
}
