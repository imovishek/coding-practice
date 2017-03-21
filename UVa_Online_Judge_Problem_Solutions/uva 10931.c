#include<stdio.h>
int main()
{
    int i,n,m,rem,count;
    char ara[100];
    while(scanf("%d",&n)!=EOF)
    {
        count=0;
        if(n==0)break;
        m=n;
        for(i=0;m>0;i++)
        {
            rem=m%2;
            ara[i]='0'+rem;
            m=m/2;
            if(rem)count++;
        }

        printf("The parity of ");
        for(--i;i>=0;i--)printf("%c",ara[i]);
        printf(" is %d (mod 2).\n",count);


    }
}
