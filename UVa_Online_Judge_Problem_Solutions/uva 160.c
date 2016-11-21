#include<stdio.h>
#include<math.h>

int main()
{

    int prime[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47, 53, 59, 61, 67, 71, 73,79,83, 89, 97,101,103,107,109,113,127,131,137,139,149};
    int n,i,fac[150],temp,max=2;
    while(scanf("%d",&n))
    {
        if(n==0)break;
        max=2;
        for(i=2; i<150; i++)fac[i]=0;
        printf("%3d! =",n);
        while(n)
        {
            temp=n;
            for(i=0;i<5 && temp>1; i++)
            {
                while(temp%prime[i]==0)
                {
                    fac[prime[i]]++;
                    temp/=prime[i];
                    if(max<prime[i])max=prime[i];
                }
            }
            if(temp>1)
            {
                fac[temp]++;
                if(max<temp)max=temp;
            }
            n--;
        }
        for(i=0;prime[i]<=max && i<35;i++)
        {
            if(i%15==0 && i)printf("\n      ");
            printf("%3d",fac[prime[i]]);
        }
        printf("\n");
    }
    return 0;
}
