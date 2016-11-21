#include<stdio.h>
#include<inttypes.h>

int main()
{

    int64_t i,n,mult=1,nin=0,len=1,lown;
    char ara[25];
    while(scanf("%"PRId64"",&n)==1){
            if(n==0)break;
            if(n<=9)printf("%"PRId64"\n",n);
    else{
            len=1;
    nin=0;mult=1;
    while(1)
    {

        if(len%2==0){nin=nin+9*mult;mult=mult*10;}
        else nin=nin+9*mult;
        if(nin>=n)break;
        lown=nin;
        len++;

    }

    lown=n-lown-1;

    if(len%2==1){ara[len/2]=lown%10+'0';lown/=10;}
    for(i=len/2-1;i>0;i--)
    {
        ara[i]=lown%10+'0';lown/=10;
        ara[len-1-i]=ara[i];
    }

    ara[len-1]=lown+1+'0';ara[0]=ara[len-1];


    for(i=0;i<len;i++)
    {
        printf("%c",ara[i]);
    }
    printf("\n");
    }

    }



    return 0;
}

