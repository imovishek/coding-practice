#include<stdio.h>
#include<math.h>
#include<string.h>
int maxi(int a, int b)
{
    if(a>b)return 1;
    return 0;
}
int gcd(int a, int b)
{
    int rem;
    if(a<b)
    {
        a=a^b;
        b=a^b;
        a=a^b;
    }
    while(b!=0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int count=0,c_all=0,i,j,temp,sq,ara[n+1],flag=0;
        memset(ara,0,sizeof(ara));
        for(i=1;i<=n-1;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                flag=0;
                temp=j*j-i*i;
                sq=sqrt(temp);
                if(sq>n)break;
                if(sq*sq==temp)
                {
                    if(maxi(sq,j) || maxi(sq,i))flag=1;
                    if(gcd(gcd(j,i),sq)==1){if(!flag)count++;}

                        if(ara[i]==0){c_all++;ara[i]++;}
                        if(ara[j]==0){c_all++;ara[j]++;}
                        if(ara[sq]==0){c_all++;ara[sq]++;}
                        printf("%d %d %d\n",i,sq,j);

                }
            }
        }

        printf("%d %d\n",count,n-c_all);

    }
    return 0;
}
