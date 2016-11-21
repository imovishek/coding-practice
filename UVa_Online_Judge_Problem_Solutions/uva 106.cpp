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
using namespace std;
typedef long long int lint;
typedef double dbl;
int gcd(int a, int b)
{
    while(b)
        b^=a^=b^=a=a%b;
    return a;
}
int ara[1000007];
int main()
{
    int n;
    while(sf1(n)!=EOF)
    {
        int sq=sqrt(n);

        memset(ara,0,(n+1)*sizeof(int));
        int triples=0;
        int acounti=0;
        int z,sqz,x,y;
        for(int i=1;i<=sq;i++)
        {
            for(int j=i+1;j<=sq;j++)
            {
                if(gcd(i,j)!=1 || !((i^j)&1))continue;
                z=i*i+j*j;
                x=j*j-i*i;
                y=2*i*j;
                if(z>n)break;
                int sig;
                sqz=sqrt(z);
                triples++;
                for(int k=1;k*z<=n;k++)
                {
                    ara[k*x]=1;
                    ara[k*z]=1;
                    ara[k*y]=1;
//                    pf("%d %d : %d %d %d %d\n",j,i,2*i*j,j*j-i*i,i*i+j*j,sig);

                }


            }
        }
        int counti=0;
        for(int i=1;i<=n;i++){
            if(ara[i]==0)counti++;
//            pf("%d %d\n",i,ara[i]);
        }
        pf("%d %d\n",triples,counti);
    }
    return 0;
}
