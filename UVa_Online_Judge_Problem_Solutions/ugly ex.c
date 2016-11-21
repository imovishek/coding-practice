#include<stdio.h>
int mem[1500];
int ugly(int n)
{
    if(n%2==0)return ugly(n/2);
    else if(n%3==0) return ugly(n/3);
    else if(n%5==0) return ugly(n/5);
    else if (n==1) return 1;
    return 0;
}

int main()
{

int i,count=0;
for(i=0;i<1500;i++)mem[i]=0;
for(i=1;count<=1500;i++){
if(ugly(i)){count++;mem[count]=1;
printf("%d\n",i);}
}
printf("%d\n",--i);
return 0;
}
