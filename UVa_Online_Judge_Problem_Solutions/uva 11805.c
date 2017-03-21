#include<stdio.h>
int main()
{

    int i,n,k,p,test;
scanf("%d",&test);
for(i=1;i<=test;i++)
{
   scanf("%d %d %d",&n,&k,&p);
   k=(k+p%n)%n;
   if(k==0)k=n;
    printf("Case %d: %d\n",i,k);
}
    return 0;

}
