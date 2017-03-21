#include<stdio.h>
int main()
{

    int i,n;
    char ara[100];
    while(scanf("%d",&n)==1)
    {

        if(n<0)break;
        if(n==0) printf("0\n");
        else{
        for(i=0;n>0;i++)
        {
            ara[i]=n%3+'0';
            n=n/3;
        }

        ara[i]='/0';i--;
        for(;i>=0;i--)
        {
            printf("%c",ara[i]);
        }
        printf("\n");

        }
    }
    return 0;
}
