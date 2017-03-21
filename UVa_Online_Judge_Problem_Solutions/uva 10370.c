#include<stdio.h>

int main()
{
    freopen("input.txt","r",stdin);
int test,i,n,k,sum;
double avg,percnt;
scanf("%d",&test);
while(test--)
{   sum=0;
k=0;
    scanf("%d",&n);
    int ara[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
        sum+=ara[i];

    }
    avg=sum/n;
     for(i=0;i<n;i++)
        {
            if(ara[i]>avg)k++;
        }
     percnt=(double)k/n*100;
     printf("%.3f%%\n",percnt);
}


return 0;
}
