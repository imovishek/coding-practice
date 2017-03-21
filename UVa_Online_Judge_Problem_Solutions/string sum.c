#include<stdio.h>
void str_sum(int ara1[],int ara2[],int ara3[]);
int main()
{
    int i,ara1[11],ara2[11],ara3[11];
    for(i=0;i<10;i++)ara3[i]=-1;ara1[10]=-1;ara2[10]=-1;
    for(i=0;i<10;i++)scanf("%d",&ara1[i]);
    for(i=0;i<10;i++)scanf("%d",&ara2[i]);
    str_sum(ara1,ara2,ara3);
    for(i=0;i<10;i++)printf("%d ",ara3[i]);

    return 0;
}
void str_sum(int ara1[],int ara2[],int ara3[])
{
    int i,temp,k;
    for(i=0;ara1[i]!=-1;i++)
    {
        if(ara3[i]==-1)ara3[i]=0;
        temp=ara1[i]+ara2[i]+ara3[i];
        k=0;
        while(temp>9)
        {
            if(ara3[i+k]==-1)ara3[i+k]=1;
            else ara3[i+k]++;
            temp/=10;
            k++;
        }
    }
}
