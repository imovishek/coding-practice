#include<stdio.h>
long long GCD(long long a, long long b)
{
    long long x;
    if(a<b){x=a;a=b;b=x;}
    while(b>0)
    {
        x=a%b;
        a=b;
        b=x;
    }
    return a;
}
int main()
{
    long long temp=0,up=0,dn=0;
    int t,n;
    int i,j;
    scanf("%d",&t);
   for(i=1;i<=t;i++)
   {
        dn=0;
       scanf("%d",&n);
       up=1;
         long long ara[n];

       for(j=0;j<n;j++)
       {
            scanf("%ld",&ara[j]);
            up*=ara[j];
       }

       for(j=0;j<n;j++)
       {
            dn+=up/ara[j];

       }
       up*=n;

       temp=GCD(up,dn);

       up/=temp;
       dn/=temp;

       printf("Case %d: %ld/%ld\n",i,up,dn);

   }
return 0;
}
