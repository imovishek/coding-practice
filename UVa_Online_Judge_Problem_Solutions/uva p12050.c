#include<stdio.h>
int is_palindrome(int n)
{

    int x=0,m=n;

    while(1)
    {
        x=x*10+m%10;
        m=(m-(m%10))/10;
        if(m==0)break;
    }
    if(x==n)return 1;
    return 0;
}
void main()
{
    int n,i,count=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=1;n>0;i++)
        {
            if(is_palindrome(i))n--;
        }

        printf("%d\n",i-1);
    }
}

