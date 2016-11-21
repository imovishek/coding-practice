#include<stdio.h>

int main()
{
    
   
int n,i,j,k,sum=0;

while(scanf("%d",&n)==1)
{
    sum=0;


    int ara[n];
   for(j=0;j<n;j++)scanf("%d",&ara[j]);
    for(i=n;i>0;i--)
    {
        for(j=0,k=0;j<n;j++,k++)
        {
            if(ara[j]==i){break;}
            else if (ara[j]<i) {k--;}
        }

        sum+=k;
    }
    printf("Minimum exchange operations : %d\n",sum);
    }

return 0;
}
