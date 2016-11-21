#include<stdio.h>
int main()
{
int a,b,c,max;
while(scanf("%d %d %d",&a,&b,&c)==3)
{
    max=0;
    if(a==0 && b==0 && c==0) break;
    if(a>b && a>c){max=a;a=0;}
    else if(b>a && b>c){max=b;b=0;}
    else {max=c;c=0;}
    if(max*max==a*a+b*b+c*c)printf("right\n");
    else printf("wrong\n");
}


return 0;
}
