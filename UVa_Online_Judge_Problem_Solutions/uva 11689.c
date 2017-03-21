#include<stdio.h>
int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&a,&b,&c);
        a=a+b;
        b=0;
        while(a>=c)
        {
            b+=a/c;
            a=a/c+a%c;


        }
        printf("%d\n",b);
    }


    return 0;
}
