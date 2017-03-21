#include<stdio.h>

int main()
{
    int t;
    char a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("\n%c%c%c",&a,&b,&c);
        printf("%d\n",a+b+c);
    }

    return 0;
}


