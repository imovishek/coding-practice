#include<stdio.h>
int main()
{
    int i,a,b,ntest;
    scanf("%d",&ntest);
  for(i=0;i<ntest;i++)
    {
     scanf("%d %d",&a,&b);
     if(0!=b%a) printf("-1\n");
     else printf("%d %d\n",a,b);

    }

    return 0;
}
