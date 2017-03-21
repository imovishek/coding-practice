#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back()
#define pf printf
#define hi printf("hi!\n");
#define sf scanf
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pcase(x) printf("Case %d: ",x)
#define mx 316300
#define setit(x) primes[x>>6]|=(1<<((x&63)>>1))
#define onit(x) (primes[x>>6] & (1<<((x&63)>>1)))
#define m 563
#define MX 316300
using namespace std;
typedef long long int lint;
typedef double dbl;
int primes[(MX/64)+7]= {0};
int allp[MX];

void seive()
{
    printf("%d\n",sizeof(primes)/sizeof(int));
    allp[0]=2;
    int i,sq,j,k=1;
    sq=m;
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
           if(i<=100) pf("%d ",i);
        }
    }
    printf("%d\n",k);


}

int main()
{
    seive();
    return 0;
}
