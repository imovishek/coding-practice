#include<stdio.h>

int main()
{
int a,b,c,test;
scanf("%d",&test);
while(test--)
{
    scanf("%d %d %d",&a,&b,&c);
    if(a+b<=c || a+c<=b || b+c<=a) printf("Wrong!!\n");
    else printf("OK\n");
}

return 0;
}
