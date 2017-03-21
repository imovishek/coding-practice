#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
int ones;
typedef long long int lint;
int lasttwo(int n, int len)
{
    int i,one;
    ones=0;
    for(i=0;i<len;i++)
        if(n&(1<<i))ones++;
//    if(ones!=2)return 0;
    one=ones;
    for(i=len-1;one--;i--)
    if((n&(1<<(i)))==0)return 0;
    return 1;
}
int main()
{
    int n,i,t,len,f0,f1,sp=1,test=1,j,first0,counti;

    scanf("%d",&t);
    while(t-- && scanf("%d",&n))
    {
        counti=0;
        f1=-1;
        f0=-1;
        sp=1;

        for(i=31; i>=0; i--)
            if(n&(1<<i))break;
        len=i+1;

        first0=len-1;
        for(i=first0; i>-1; i--)
        {
            if((n&1<<i)==0)break;
        }
        first0=i;

        for(i=1; i<len; i++)
            sp=(sp<<1)|1;


        for(i=len-1; i>=0; i--)
        {
            if((n&1<<i)==0)
            {
//                printf("0");
            }
            else
            {
//                printf("1");
                counti++;
            }
        }
//        printf("\n");
        if(counti==1)n<<=1;
        else if(counti==len)
        {
            n=(1<<(len-1))^sp;
            n|=1<<len;
        }
        else if(lasttwo(n,len))
        {
            int one=ones;
            one--;
            for(i=len-2;one--;i--)
             n&=(1<<(i))^sp;
             n<<=1;
            for(i=0;i<ones-1;i++)
                n|=1<<i;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if((n&(1<<i))==0 && f0==0)
                {
                    n|=1<<i;
                    f0=i;
                }
                else if((n&(1<<i)) && f0==-1)f0=0;
//                for(j=len-1; j>=0; j--)
//                {
//                    if((n&(1<<j))==0)
//                    {
//                        printf("0");
//                    }
//                    else printf("1");
//                }
//                printf("    %d(%d)\n",i,f0);
            }
            for(i=f0-1; i>-1; i--)
            {
                if((n&(1<<i)) && f1==-1)
                {
                    n&=(1<<i)^sp;
                    f1=1;
                }
//                for(j=len-1; j>=0; j--)
//                {
//                    if((n&(1<<j))==0)
//                    {
//                        printf("0");
//                    }
//                    else printf("1");
//                }
//                printf("    %d(%d)\n",i,f0);
            }
            counti=0;
            for(i=f0-1;i>-1;i--)
            {
                if((n&(1<<i)) )
                {
                    n&=(1<<i)^sp;
                    counti++;
                }
            }
            for(i=0;i<counti;i++)
            {
                n|=(1<<i);
            }
        }
            printf("Case %d: %d\n",test++,n);
        }
        return 0;
    }
