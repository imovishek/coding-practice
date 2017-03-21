#include<stdio.h>
int main()
{
int n,sum=0,a;
char ara[7];
scanf("%d",&n);
while(n--)
{
    scanf("%s",ara);
    if(!strcmp(ara,"donate")){scanf("%d",&a);sum+=a;}
    else if(!strcmp(ara,"report"))printf("%d\n",sum);
}


return 0;
}
