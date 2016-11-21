#include<stdio.h>
int main()
{

    int i,j,n,avg,sum;
    for(j=1;scanf("%d",&n)==1;j++){
            if(n==0)break;
            sum=0;
    int ara[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
        sum+=ara[i];
    }
    avg=sum/n;
    sum=0;
    for(i=0;i<n;i++)
    {
        if(ara[i]>avg)sum+=ara[i]-avg;
    }
    printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,sum);
    }

return 0;
}
