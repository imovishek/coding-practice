#include<stdio.h>
int main()
{
int ntest,nque,i,j,count=0,k=1;

scanf("%d",&ntest);
for(i=0;i<ntest;i++)
{
    scanf("%d",&nque);
    char cara[nque];
    int ara[nque][2];

    for(j=0;j<nque;j++)
    {
        scanf("%d %d",&ara[j][0],&ara[j][1]);
        cara[j]=getchar();
        printf("%d %d %c",ara[j][0],ara[j][1],cara[j]);
    }
    for(j=0;j<nque-1;j++)
    {
        if(ara[j][1]==1 && cara[j]=='c')
        {
            for(k=1;k<nque;k++)
            {
              if(ara[j+k][1]==0 && cara[j+k]=='i' && ara[j][0]>ara[j+k][0] )
                count++;
            }
        }
        else if(ara[j][1]==0 && cara[j]=='i')
        {
            for(k=1;k<nque;k++)
            {
              if(ara[j+k][1]==1 && cara[j+k]=='c' && ara[j][0]<ara[j+k][0] )
                count++;
            }
        }
        nque--;
    }
    printf("%d\n",count);
    count=0;
}
return 0;
}
