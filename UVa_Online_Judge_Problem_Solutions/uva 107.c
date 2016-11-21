#include<stdio.h>
#include<inttypes.h>

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int64_t i,j,H,n,m,k,sum,mult,mult2,sum2,h;
while(1)
{
    sum=1;
    mult=1;


    scanf("%"PRId64" %"PRId64"",&H,&n);

    if(H==0 && n==0)break;
    j=2;
    m=n;
    k=0;
    mult2=H;
    sum2=H;


     h=H;

    for(i=j;m>1;)
    {
        if(m%i==0 && h%(i+1)==0) {m=m/i;k++;h=h/(i+1);}
        else {m=n;i=++j;k=0;h=H;}
    }

    if(n==1){i=1;k=0;for(m=H;m>1;){m=m/2;k++;}}

    for(j=0;j<k-1;j++)
    {
        mult*=i;
        sum=sum+mult;

        mult2=mult2*i/(i+1);

        sum2=sum2+mult2;
    }

        mult2=mult2*i/(i+1);

        sum2=sum2+mult2;
        if(H==1 && n==1){sum=0;sum2=1;}
    printf("%"PRId64" %"PRId64"\n",sum,sum2);
}

return 0;
}
