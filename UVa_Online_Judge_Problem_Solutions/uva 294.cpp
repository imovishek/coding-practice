#include<cstdio>
#include<cmath>
#include<vector>
#define m 1000010
using namespace std;
vector <bool> primes(m);
bool is_prime(long long int n)
{
    if(n<2)return 0;
    if(n==2)return 1;
    if(n%2==0)return 0;
    return !primes[n];
}
void seive()
{
    for(int i=3; i*i<=m; i+=2)
    {
        if(primes[i]==0)
        {
            for(int j=i*i; j<=m; j+=i+i)
            {
                primes[j]=1;
            }
        }
    }
}
using namespace std;

int main()
{
    long long int i,j,t,sq,count=0,max,q,p,s_p;
    long long int n,sum;
    scanf("%lld",&t);
    seive();
    vector <long long int> onlyprime;
    onlyprime.push_back(2);
    for(i=3; i<m; i+=2)if(is_prime(i))
        {
            onlyprime.push_back(i);
        }
    for(i=1; i<=t; i++)
    {
        max=0;
        sum=1;
        scanf("%lld %lld",&p,&q);
        printf("Between %lld and %lld, ",p,q);
        if(p>q)
        {
            p=p^q;
            q=p^q;
            p=p^q;
        }
        for(;p<=q; p++)
        {
            n=p;
            sq=sqrt(n);
            for(j=0; onlyprime[j]<=sq && n>1; j++)
            {
                count=1;
                while(n%onlyprime[j]==0)
                {
                    n/=onlyprime[j];
                    count++;
                }

                sum*=count;
            }

            if(n>1)sum*=2;
            if(sum>max){max=sum;s_p=p;}
        }
        printf("%lld has a maximum of %lld divisors.\n",s_p,max);
    }
    return 0;
}
