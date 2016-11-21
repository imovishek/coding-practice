#include<stdio.h>
int main(){


int t,a,b,c,flag;
double ar;
scanf("%d",&t);
while(t--)
{
    flag=0;
    scanf("%d %d %d",&a,&b,&c);

    if(a*a==b*b+c*c)ar=.5*b*c;
    else if(b*b==c*c+a*a)ar=.5*a*c;
    else if (c*c==a*a+b*b)ar=.5*a*b;
    else {flag=1;}
    if(!flag)printf("%.4lf\n",ar);
    else printf("-1\n");
}




return 0;
}
