#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<inttypes.h>
#define setit(x) primes[x>>6]|=(1<<((x&63)>>1))
#define onit(x) (primes[x>>6] & (1<<((x&63)>>1)))
#define m 156250
#define MX 10000008
typedef long long int lint;
int primes[(MX/64)+7]= {0};
int allp[MX];

void seive()
{
    printf("%d\n",sizeof(primes)/sizeof(int));
    allp[0]=2;
    int i,sq,j,k=1;
    sq=sqrt(MX);
    for(i=3; i<=sq; i+=2)
    {
        if(!onit(i))
        {
            for(j=i*i; j<MX; j+=i<<1)
                setit(j);
        }
    }
    for(k=1,i=3; i<MX; i+=2){
        if(!onit(i))
        {
            allp[k++]=i;
        }
    }
    printf("%d\n",k);


}


int main()
{
    seive();
    lint n;
    lint t,i,j,counti,ans;
    scanf("%I64d",&t);
    t++;

    for(i=1; i<t; i++)
    {

        ans=1;
        scanf("%I64d",&n);

        for(j=0; j<664579 && allp[j]*allp[j]<=n; j++)
        {
            counti=1;
            while(n%allp[j]==0)
            {
                n/=allp[j];
                counti++;
            }
            if(j==0)counti=1;
            ans*=counti;
        }
        if(n>2)ans=ans<<1;
        ans--;
        printf("Case %I64d: %I64d\n",i,ans);

    }
    return 0;
}
