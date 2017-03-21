#include<stdio.h>
#define sf scanf
#define pf printf

char isprime(int n)
{
    if(n<2) return 0;
    if(n==2)return 1;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

int main()
{
    int t,i,n;
    int a;
    scanf("%d",&t);
    while(t--)
    {
        int counti=0;
        for(i=0; i<10; i++){
            sf("%d",&a);
            if(isprime(a))counti++;
        }
        pf("%d\n",counti);
    }

    return 0;
}


