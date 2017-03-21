#include<stdio.h>
int main()
{

    int j,i,ara[12],ara2[12],sum,used;
    for(j=1;scanf("%d",&sum)!=EOF;j++)
    {
        if(sum<0)break;
        for(i=0;i<12;i++)scanf("%d",&ara[i]);
        for(i=0;i<12;i++)scanf("%d",&ara2[i]);
        printf("Case %d:\n",j);
        for(i=0;i<12;i++)
        {
            if(ara2[i]<=sum){printf("No problem! :D\n");used=ara2[i];}
            else {printf("No problem. :(\n");used=0;}
            sum+=ara[i]-used;
        }
    }
    return 0;
}
