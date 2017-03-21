#include<stdio.h>
int main()
{
    int lm,i,l,j,sum=0;
    int a,b,c;
    scanf("%d",&lm);
    for(i=0;i<lm;i++)
    {
        scanf("%d",&l);
        for(j=0;j<l;j++)
        {
            scanf("%d %d %d",&a,&b,&c);

            sum=sum+a*c;
        }
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}
