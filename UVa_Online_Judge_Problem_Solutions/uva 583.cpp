#include<cstdio>
#include<cmath>
#include<vector>
#define m 47000
using namespace std;

bool prime[m];
vector <int> primes;
void seive()
{
    int i,j,sq;
    for(i=4;i<m;i+=2)prime[i]=1;
    sq=sqrt(m);
    for(i=3;i<sq;i+=2)
    {
        for(j=i*i;j<m;j+=i+i)
            prime[j]=1;
    }
    primes.push_back(2);
    for(i=3;i<m;i+=2)if(!prime[i]){primes.push_back(i);}
}
int main()
{
    int n,i;
    seive();
    while(scanf("%d",&n)!=EOF)
    {
        int flag=0;
        if(n==0)break;
        printf("%d =",n);
        if(n<0){flag=1;printf(" -1");n=-n;}

        for(i=0;i<4851;i++)
        {
            if(n<47000 && !prime[n])break;
            while(n%primes[i]==0)
            {
                if(!flag){printf(" %d",primes[i]);flag=1;}
                else printf(" x %d",primes[i]);
                n/=primes[i];
            }
        }
        if(n>1)
        {
            if(!flag)printf(" %d",n);
            else printf(" x %d",n);
        }
        printf("\n");
    }
    return 0;
}
