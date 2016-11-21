#include<cstdio>
#include<cmath>
#include<vector>
#define m 10004
using namespace std;
char prime[m];
char mu[1000001];
int M[1000001];
vector<int>primes;
void seive()
{
    int i,j;
    for(i=4;i<m;i+=2)prime[i]=1;

    for(i=3;i<102;i++)
    {
        if(prime[i]==0){
        for(j=i*i;j<m;j+=i+i)
            prime[j]=1;
        }
    }
    for(i=2;i<m;i++)
        if(prime[i]==0)
            primes.push_back(i);



}
void precal()
{
    int i,j,sq,flag=1;
    seive();
//    for(i=0;i<primes.size();i++)
//    printf("%d ",primes[i]);
    mu[1]=1;
    for(int k=2;k<1000001;k++)
    {
        flag=1;
        i=k;
        if(i<m && prime[i]==0){mu[i]=-1;}
        else
        {
            sq=sqrt(i);
            int counti=0;
            for(j=0;primes[j]<=sq;j++)
            {
                if(i%primes[j]==0)
                {
                    i/=primes[j];
                    counti++;
                    if(i%primes[j]==0)
                    {
                        mu[k]=0;
                        flag=0;
                        break;
                    }
                }
            }
            if(i>1)counti++;
            if(counti==1)mu[k]=-1;
            else if(flag && counti%2==0)mu[k]=1;
            else if(flag) mu[k]=-1;
        }
    }
    M[1]=1;M[2]=-1;M[3]=-1;
    for(int i=2;i<1000001;i++)
        M[i]=M[i-1]+mu[i];

}
int main()
{
    precal();
//    for(int k=1;k<30;k++)
//        printf("%d %d %d\n",k,mu[k],M[k]);
    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%8d%8d%8d\n",n,mu[n],M[n]);
    }
    return 0;
}
