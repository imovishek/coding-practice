#include<stdio.h>

int main()
{


int test,i;
long int a,b,c;
char ch;
scanf("%d",&test);
for(i=1;i<=test;i++)
{
    scanf("%ld %ld %ld",&a,&b,&c);
    if(a<=0 || b<=0 || c<=0) ch='i';
    else if(a+b<=c || a+c<=b || b+c<=a) ch='i';
    else if (a==b && b==c) ch='e';
    else if(a==b || b==c || c==a) ch='I';
    else ch='s';
    switch(ch)
    {
    case 'i':
        printf("Case %d: Invalid\n",i);
        break;
    case 'e':
        printf("Case %d: Equilateral\n",i);
        break;
    case 'I':
        printf("Case %d: Isosceles\n",i);
        break;
    default:
        printf("Case %d: Scalene\n",i);
        break;

    }
}

return 0;
}
