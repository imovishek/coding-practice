#include<stdio.h>
int main()
{
  long long i=1,j,n=1499;
while(n)
{
i++;
j=i;
while(j>1){
if(j%2==0) j=j/2;
else if(j%3==0) j=j/3;
else if(j%5==0)j=j/5;
else break;
}
if(j==1) {n--;



printf("%lld\n",i);
}
}

    return 0;
}
