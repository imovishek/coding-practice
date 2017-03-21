#include<stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
int test,n,i,j,k,sum=0;
 scanf("%d",&test);
while(test--)
{
    sum=0;

    scanf("%d",&n);
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
    printf("Optimal train swapping takes %d swaps.\n",sum);
    }

return 0;
}
